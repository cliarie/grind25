#include <iostream>
#include <vector>
using namespace std;

int convertTimeToMinutes(int time)
{
    int hours = time / 100;
    int minutes = time % 100;
    return hours * 60 + minutes;
}

int convertMinutesToTime(int minutes)
{
    int hours = minutes / 60;
    int mins = minutes % 60;
    return hours * 100 + mins;
}

int addMinutes(int currentTime, int minutesPassed)
{
    int mins = currentTime % 100;
    int hour = currentTime / 100;
    int totalMins = mins + 60 * hour;
    totalMins += minutesPassed;
    int newMinutes = totalMins % 60;
    int newHour = totalMins / 60;
    return newHour * 100 + newMinutes;
}

int trainSchedule(vector<int> arrivalStations, vector<int> arrivalTimes, vector<int> destStations, vector<int> destTimes, int timeBtwStations)
{
    // train can hold max 5 people
    // train arrive at station 1 every 15 mins starting at 630;
    // train wait 2 mins at each station always
    // time between stations is 5 mins
    // determine number of passengers late to work, not at dest station at dest time
    // Convert times to minutes since midnight for easier calculation
    vector<int> arrivalTimesMinutes(arrivalTimes.size());
    vector<int> destTimesMinutes(destTimes.size());

    for (size_t i = 0; i < arrivalTimes.size(); ++i)
    {
        arrivalTimesMinutes[i] = convertTimeToMinutes(arrivalTimes[i]);
    }
    for (size_t i = 0; i < destTimes.size(); ++i)
    {
        destTimesMinutes[i] = convertTimeToMinutes(destTimes[i]);
    }

    // Train schedule
    int train_start_time = convertTimeToMinutes(630); // 6:30 AM
    int train_interval = 15;                          // Trains arrive every 15 minutes
    int train_capacity = 5;

    // Initialize train schedule
    vector<pair<int, int>> trains; // pair<arrival_time, capacity_left>
    for (int t = train_start_time; t < 24 * 60; t += train_interval)
    {
        trains.push_back(make_pair(convertMinutesToTime(t), train_capacity));
    }

    // Track when each passenger reaches their destination
    vector<int> passenger_dest_arrival(arrivalStations.size(), -1);

    // Process each train
    for (auto &train : trains)
    {
        int current_time = train.first;
        int capacity_left = train.second;

        for (int station = 1; station <= *max_element(arrivalStations.begin(), arrivalStations.end()); ++station)
        {
            // Add 2 minutes for waiting at the station
            current_time = addMinutes(current_time, 2);

            // Check passengers at the current station
            for (size_t p = 0; p < arrivalStations.size(); ++p)
            {
                if (arrivalStations[p] == station && arrivalTimesMinutes[p] <= convertTimeToMinutes(current_time) && passenger_dest_arrival[p] == -1)
                {
                    if (capacity_left > 0)
                    {
                        capacity_left -= 1;
                        int travel_time = (destStations[p] - station) * timeBtwStations;
                        passenger_dest_arrival[p] = convertTimeToMinutes(current_time) + travel_time;
                    }
                    else
                    {
                        break;
                    }
                }
            }

            // Move to the next station
            if (station < *max_element(arrivalStations.begin(), arrivalStations.end()))
            {
                current_time = addMinutes(current_time, timeBtwStations);
            }
        }
    }

    // Determine how many passengers are late
    int late_count = 0;
    for (size_t p = 0; p < passenger_dest_arrival.size(); ++p)
    {
        if (passenger_dest_arrival[p] == -1 || passenger_dest_arrival[p] > destTimesMinutes[p])
        {
            late_count++;
        }
    }

    return late_count;
}

int main()
{
#ifdef LOCAL_TESTING
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    // int n;
    // cin >> n;
    // vector<int> arrivalStations(n), arrivalTimes(n), destStations(n), destTimes(n);
    // for (auto &a : arrivalStations)
    //     cin >> a;
    // for (auto &a : arrivalTimes)
    //     cin >> a;
    // for (auto &a : destStations)
    //     cin >> a;
    // for (auto &a : destTimes)
    //     cin >> a;
    // int timeBtwStations;
    // cin >> timeBtwStations;

    vector<int> arrivalStations = {1, 1, 1, 2};
    vector<int> arrivalTimes = {620, 620, 620, 650};
    vector<int> destStations = {2, 2, 3, 3};
    vector<int> destTimes = {700, 700, 645, 655};
    int timeBtwStations = 5; // Fixed time between stations

    // peak 6 trains
    cout << trainSchedule(arrivalStations, arrivalTimes, destStations, destTimes, timeBtwStations) << endl;
    return trainSchedule(arrivalStations, arrivalTimes, destStations, destTimes, timeBtwStations);
}

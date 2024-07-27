#include <vector>
#include <algorithm>
#include <iostream>

int airportGates(const std::vector<int> &landingTimes, const std::vector<int> &takeOffTimes, int maxWaitTime, int initialPlanes)
{
    int numGates = initialPlanes;
    int maxGates = numGates;
    std::vector<int> maxWaitTimes;

    for (int t : landingTimes)
    {
        int hour = t / 100;
        int minutes = t % 100;
        int mm = minutes + (maxWaitTime % 60);
        int mh = (hour + (maxWaitTime / 60) + (mm / 60)) % 24;
        mm = mm % 60;
        int mt = (mh * 100) + mm;
        maxWaitTimes.push_back(mt);
    }

    std::sort(maxWaitTimes.begin(), maxWaitTimes.end());

    size_t i = 0, j = 0;
    while (i < takeOffTimes.size() && j < maxWaitTimes.size())
    {
        if (takeOffTimes[i] < maxWaitTimes[j])
        {
            numGates--;
            i++;
        }
        else
        {
            numGates++;
            maxGates = std::max(numGates, maxGates);
            j++;
        }
    }

    while (i < takeOffTimes.size())
    {
        numGates--;
        i++;
    }

    while (j < maxWaitTimes.size())
    {
        numGates++;
        maxGates = std::max(numGates, maxGates);
        j++;
    }

    return maxGates;
}

int main()
{
    std::vector<int> landingTimes = {630, 645, 730, 1100};
    std::vector<int> takeOffTimes = {700, 845, 1015, 1130};
    int maxWaitTime = 20;
    int initialPlanes = 1;

    int result = airportGates(landingTimes, takeOffTimes, maxWaitTime, initialPlanes);
    std::cout << "Maximum number of gates needed: " << result << std::endl;

    return 0;
}

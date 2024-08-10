#include <iostream>
#include <unordered_map>
#include <vector>
#include <map>

using namespace std;

class Subscriber {
private:
    unordered_map<int, pair<double, double>> positions; // TruckId -> (x, y)
    unordered_map<int, vector<pair<int, pair<double, double>>>> updates; // TruckId -> [(ClientId, (dx, dy))]
    unordered_map<int, unordered_map<int, pair<double, double>>> subscribers; // ClientId -> TruckId -> (last known x, last known y)

public:
    Subscriber(int n, const vector<pair<double, double>>& initialPositions) {
        for (int i = 0; i < n; ++i) {
            positions[i] = initialPositions[i];
        }
    }

    void subscribeToTruck(int clientId, int truckId) {
        if (positions.find(truckId) != positions.end()) {
            auto pos = positions[truckId];
            subscribers[clientId][truckId] = pos;
            cout << "S " << clientId << " " << truckId << " " << pos.first << " " << pos.second << endl;
        }
    }

    void updateTruckPosition(int truckId, double deltaX, double deltaY) {
        if (positions.find(truckId) != positions.end()) {
            positions[truckId].first += deltaX;
            positions[truckId].second += deltaY;
            for (auto& sub : subscribers) {
                int clientId = sub.first;
                if (sub.second.find(truckId) != sub.second.end()) {
                    updates[truckId].emplace_back(clientId, make_pair(deltaX, deltaY));
                }
            }
        }
    }

    void requestUpdates(int clientId) {
        for (auto& sub : subscribers[clientId]) {
            int truckId = sub.first;
            for (auto& update : updates[truckId]) {
                if (update.first == clientId) {
                    cout << "U " << clientId << " " << truckId << " " << update.second.first << " " << update.second.second << endl;
                }
            }
        }
        // Clear the updates for the client
        for (auto& sub : subscribers[clientId]) {
            int truckId = sub.first;
            updates[truckId].erase(remove_if(updates[truckId].begin(), updates[truckId].end(), [clientId](const auto& update) {
                return update.first == clientId;
            }), updates[truckId].end());
        }
    }
};

int main() {
    int N;
    cin >> N;
    vector<pair<double, double>> initialPositions(N);
    for (int i = 0; i < N; ++i) {
        cin >> initialPositions[i].first >> initialPositions[i].second;
    }

    Subscriber subscriber(N, initialPositions);
    string command;

    while (cin >> command) {
        if (command == "S") {
            int clientId, truckId;
            cin >> clientId >> truckId;
            subscriber.subscribeToTruck(clientId, truckId);
        } else if (command == "U") {
            int truckId;
            double deltaX, deltaY;
            cin >> truckId >> deltaX >> deltaY;
            subscriber.updateTruckPosition(truckId, deltaX, deltaY);
        } else if (command == "R") {
            int clientId;
            cin >> clientId;
            subscriber.requestUpdates(clientId);
        }
    }

    return 0;
}

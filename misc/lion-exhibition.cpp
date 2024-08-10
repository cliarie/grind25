#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class LionCompetition {
private:
    struct Lion {
        string name;
        int height;
        int enterTime;
        int exitTime;
    };

    vector<Lion> ourLions;
    unordered_map<string, Lion> lionMap;
    set<pair<int, string>> ourCurrentLions; // {height, name}
    multiset<int> competitorLions; // heights only
    int currentTime = 0;

public:
    LionCompetition(const vector<pair<string, int>>& lions, const vector<tuple<string, int, int>>& schedule) {
        for (const auto& lion : lions) {
            string name = lion.first;
            int height = lion.second;
            lionMap[name] = {name, height, -1, -1}; // initializing with invalid times
        }

        for (const auto& event : schedule) {
            string name = get<0>(event);
            int enterTime = get<1>(event);
            int exitTime = get<2>(event);
            if (lionMap.find(name) != lionMap.end()) {
                lionMap[name].enterTime = enterTime;
                lionMap[name].exitTime = exitTime;
            }
        }

        for (const auto& kv : lionMap) {
            ourLions.push_back(kv.second);
        }
    }

    void lionEntered(int currentTime, int height) {
        this->currentTime = currentTime;
        bool isOurLion = false;
        for (const auto& lion : ourLions) {
            if (lion.height == height && lion.enterTime == currentTime) {
                ourCurrentLions.insert({height, lion.name});
                isOurLion = true;
                break;
            }
        }
        if (!isOurLion) {
            competitorLions.insert(height);
        }
    }

    void lionLeft(int currentTime, int height) {
        this->currentTime = currentTime;
        bool isOurLion = false;
        for (const auto& lion : ourLions) {
            if (lion.height == height && lion.exitTime == currentTime) {
                ourCurrentLions.erase({height, lion.name});
                isOurLion = true;
                break;
            }
        }
        if (!isOurLion) {
            auto it = competitorLions.find(height);
            if (it != competitorLions.end()) {
                competitorLions.erase(it);
            }
        }
    }

    vector<string> getBiggestLions(int currentTime) {
        this->currentTime = currentTime;
        vector<string> result;
        if (!competitorLions.empty()) {
            int maxCompetitorHeight = *competitorLions.rbegin();
            for (const auto& lion : ourCurrentLions) {
                if (lion.first >= maxCompetitorHeight) {
                    result.push_back(lion.second);
                }
            }
        } else {
            for (const auto& lion : ourCurrentLions) {
                result.push_back(lion.second);
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};

int main() {
    int numLions;
    cin >> numLions;
    vector<pair<string, int>> lions(numLions);
    for (int i = 0; i < numLions; ++i) {
        cin >> lions[i].first >> lions[i].second;
    }

    int numSchedules;
    cin >> numSchedules;
    vector<tuple<string, int, int>> schedule(numSchedules);
    for (int i = 0; i < numSchedules; ++i) {
        cin >> get<0>(schedule[i]) >> get<1>(schedule[i]) >> get<2>(schedule[i]);
    }

    LionCompetition competition(lions, schedule);

    string command;
    while (cin >> command) {
        if (command == "enter") {
            int currentTime, height;
            cin >> currentTime >> height;
            competition.lionEntered(currentTime, height);
        } else if (command == "exit") {
            int currentTime, height;
            cin >> currentTime >> height;
            competition.lionLeft(currentTime, height);
        } else if (command == "inspect") {
            int currentTime;
            cin >> currentTime;
            vector<string> result = competition.getBiggestLions(currentTime);
            cout << result.size() << " ";
            for (const auto& name : result) {
                cout << name << " ";
            }
            cout << endl;
        }
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <tuple>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

class Q1 {
public:
    Q1(const vector<pair<string, int>>& elephants, const vector<tuple<string, int, int>>& schedule) {
        // map of our elephants' names to their sizes
        for (const auto& elephant : elephants) {
            sizeMap[elephant.first] = elephant.second;
        }

        // schedule sorted by time of arrival/leaving
        for (const auto& event : schedule) {
            string name;
            int arrival, departure;
            tie(name, arrival, departure) = event;
            this->schedule.push_back({name, arrival, "arrive"});
            this->schedule.push_back({name, departure, "depart"});
            ignoreMap[{sizeMap[name], arrival, "arrival"}]++;
            ignoreMap[{sizeMap[name], departure, "departure"}]++;
        }

        sort(this->schedule.begin(), this->schedule.end(), [](const auto& a, const auto& b) {
            return get<1>(a) < get<1>(b);
        });

        si = 0;
    }

    void elephantEntered(int time, int height) {
        auto key = make_tuple(height, time, string("arrival"));
        if (ignoreMap[key] > 0) {
            ignoreMap[key]--;
        } else {
            others.push(-height);
        }
    }

    void elephantLeft(int time, int height) {
        auto key = make_tuple(height, time, string("departure"));
        if (ignoreMap[key] > 0) {
            ignoreMap[key]--;
        } else {
            othersLeft[height]++;
        }
    }

    vector<string> getBiggestElephants(int time) {
        // flush my set of elephants to the ones that
        // are currently in the room based on time
        while (si < schedule.size() && get<1>(schedule[si]) <= time) {
            string name = get<0>(schedule[si]);
            string type = get<2>(schedule[si]);
            if (type == "arrive") {
                mine.insert({name, sizeMap[name]});
            } else {
                mine.erase({name, sizeMap[name]});
            }
            si++;
        }

        // flush the heap of other elephants to find the
        // one who is the tallest and still present
        while (!others.empty()) {
            int cur = abs(others.top());
            if (othersLeft[cur] > 0) {
                others.pop();
                othersLeft[cur]--;
            } else {
                break;
            }
        }

        int tallestRival = others.empty() ? 0 : abs(others.top());
        vector<string> candidates;
        for (const auto& p : mine) {
            if (p.second >= tallestRival) {
                candidates.push_back(p.first);
            }
        }
        sort(candidates.begin(), candidates.end());
        return candidates;
    }

private:
    unordered_map<string, int> sizeMap;
    set<pair<string, int>> mine;
    map<tuple<int, int, string>, int> ignoreMap;
    priority_queue<int> others;
    unordered_map<int, int> othersLeft;
    vector<tuple<string, int, string>> schedule;
    int si;
};

int main() {
    Q1 sol({{"marry", 300}, {"rob", 250}}, {{"marry", 10, 15}, {"rob", 13, 20}});
    sol.elephantEntered(8, 200);
    sol.elephantEntered(10, 310);
    sol.elephantEntered(10, 300);
    for (const auto& e : sol.getBiggestElephants(11)) {
        cout << e << " ";
    }
    cout << endl;
    sol.elephantEntered(13, 250);
    sol.elephantLeft(13, 310);
    for (const auto& e : sol.getBiggestElephants(13)) {
        cout << e << " ";
    }
    cout << endl;
    sol.elephantLeft(15, 300);
    for (const auto& e : sol.getBiggestElephants(16)) {
        cout << e << " ";
    }
    cout << endl;
    sol.elephantLeft(16, 310);
    sol.elephantLeft(20, 310);

    return 0;
}

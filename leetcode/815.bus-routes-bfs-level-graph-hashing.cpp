#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    bool common(vector<int> &a, vector<int> &b){
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()){
            if (a[i] == b[j]) return true;
            if (a[i] < b[j]) i++;
            else j++;
        }
        return false;
    }

    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        unordered_map<int, vector<int>> m; // stop has which buses
        int n = routes.size();
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < routes[i].size(); ++j){
                m[routes[i][j]].push_back(i);
            }
        }
        for (auto &v : routes) sort(v.begin(), v.end());
        vector<set<int>> graph(n);
        for (int i = 0; i < n; ++i){
            for (int j = i + 1; j < n; ++j){
                if (common(routes[i], routes[j])){
                    graph[i].insert(j);
                    graph[j].insert(i);
                }
            }
        }

        // for (auto it = m.begin(); it != m.end(); ++it){
        //     auto v = it->second;
        //     for (int i = 0; i < v.size(); ++i){
        //         for (int j = i + 1; j < v.size(); ++j){
        //             graph[v[i]].insert(v[j]);
        //             graph[v[j]].insert(v[i]);
        //         }
        //     }
        // }

        // for (auto i : graph){
        //     for (auto j : i) cout << j << " " ;
        //     cout << endl;
        // }

        int total = 0;
        queue<int> q;
        set<int> targets;
        for (int t : m[target]) targets.insert(t);
        vector<int> visited(n);
        for (int t : m[source]) q.push(t);
        while(!q.empty()){
            int s = q.size();
            total++;
            while(s--){
                int cur = q.front();
                q.pop();
                visited[cur] = 1;
                if (targets.find(cur) != targets.end()) return total;
                for (auto n : graph[cur]){
                    if (!visited[n]) q.push(n);
                }
            }
        }
        return -1;
    }
};

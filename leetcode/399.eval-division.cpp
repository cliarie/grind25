#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    double dfs(map<string, vector<pair<double, string>>> &graph, string cur, string end, map<string, int> &visited){
        cout << cur << " " << end << " " << endl;
        visited[cur] = 1;
        if (cur == end) return 1.0;
        for (auto n : graph[cur]){
            cout << n.second << endl;
            if (!visited[n.second]) {
                cout << "NOTVISITED" << endl;
                //cur = n.second;
                double res = dfs(graph, n.second, end, visited);
                if (res != -1) return res*n.first;
            }
        }
        return -1;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // store a: {3, b}
        // store b: {1/3, a}
       map<string, vector<pair<double, string>>> graph;
       int n = equations.size();
       for (int i = 0; i < n; ++i){
        graph[equations[i][0]].push_back({values[i], equations[i][1]});
        graph[equations[i][1]].push_back({1 / values[i], equations[i][0]});
       }
        
        vector<double> ans(queries.size(), 0);
        for (int i = 0; i < queries.size(); ++i){
            map<string, int> visited;
            string start = queries[i][0], end = queries[i][1];
            if (graph.find(start) == graph.end() || graph.find(end) == graph.end()) ans[i] = -1;
            else {
                ans[i] = dfs(graph, start, end, visited);
            }
        }

        return ans;
    }
};

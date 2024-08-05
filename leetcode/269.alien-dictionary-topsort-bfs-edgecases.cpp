#include <queue>
#include <map>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string alienOrder(vector<string>& words) {
        int n = words.size();
        map<char, int> indegree;
        map<char, unordered_set<char>> graph;
        for (auto &word : words){
            for (auto c : word){
                indegree[c] = 0;
            }
        }

        for (int i = 1; i < n; ++i){
            string cur = words[i], prev = words[i - 1];
            int idx = 0;
            if (prev.length() > cur.length() && prev.compare(0, cur.length(), cur) == 0) return "";
            while(idx < prev.length()){
                if (cur[idx] != prev[idx]) break;
                idx++;
                // anything before first difference doesnt matter ? mess up indegree
                // if (idx != 0) {
                //     if (graph[cur[idx-1]].find(cur[idx]) != graph[cur[idx-1]].end()) continue;
                //     //cout << cur[idx-1] << endl;
                //     graph[cur[idx - 1]].insert(cur[idx]);
                //     // if (indegree.find(cur[idx-1]) == indegree.end()) indegree[cur[idx-1]] = 0;
                //     indegree[cur[idx]]++;
                // }
            }
            if (graph[prev[idx]].find(cur[idx]) != graph[prev[idx]].end()) continue;
            if (idx >= prev.length()) continue;
            graph[prev[idx]].insert(cur[idx]);
            // if (indegree.find(prev[idx]) == indegree.end()) indegree[prev[idx]] = 0;
            indegree[cur[idx]]++;
        }

        //if (indegree.empty()) return words[0];

        queue<char> q;
        for (auto &e : indegree){
            if (e.second == 0) {
                q.push(e.first);
                e.second--;
            }
        }

        string ans = "";
        while(!q.empty()){
            char cur = q.front();
            q.pop();
            if (isalpha(cur)) ans += cur;
            for (auto n : graph[cur]){
                indegree[n]--;
                if (!indegree[n]) q.push(n);
            }
        }

        return (ans.length() == indegree.size()) ? ans : "";
    }
};

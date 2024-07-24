class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // finding the center of center of the graph
        // graph can have at most one / two centers, otherwise it would form triangle / square, etc. which would make graph cyclic
        // return the centers (aka trim the graph so there are max 2 nodes left)
        if (n == 0) return {}; if (n == 1) return {0}; if (n == 2) return edges[0];
        vector<vector<int>> graph(n);
        vector<int> indegree(n);
        for (auto i : edges){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
            indegree[i[0]]++;
            indegree[i[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; ++i){
            if (indegree[i] == 1){
                cout << i << endl;
                q.push(i);
            }
        }

        vector<int> ans;
        while (!q.empty()){
            int size = q.size();
            ans.clear();
            while(size--){
                int c = q.front();
                ans.push_back(c);
                q.pop();
                for (int i : graph[c]){
                    indegree[i]--;
                    if (indegree[i] == 1) {
                        q.push(i);
                    }
                }
            }
        }

        if (ans.empty()) return {0};
        return ans;
    }
};

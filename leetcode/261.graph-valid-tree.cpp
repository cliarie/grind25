class Solution {
public:
    int dfs(vector<vector<int>> &graph, vector<int> &visited, int cur){
        visited[cur] = -1;
        int count = 1;
        for (auto i : graph[cur]){
            if (visited[i] != -1) count += dfs(graph, visited, i);
        }
        return count;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        // cycle detection ->topsort 
        vector<vector<int>> graph(n);
        vector<int> indegrees(n);
        
        if (n == 1) return true;

        for (auto i : edges){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
            indegrees[i[0]]++;
            indegrees[i[1]]++;
        }

        int count = 0;
        queue<int> q;
        for (int i = 0; i < n; ++i){
            if (indegrees[i] == 1) {
                q.push(i);
                indegrees[i]--;
                count++;
            }
        }

        while(!q.empty()){
            int c = q.front();
            q.pop();
            for (auto n : graph[c]){
                indegrees[n]--;
                if (indegrees[n] == 1) {
                    count++;
                    q.push(n);
                }
            }
        }


        cout << count << endl;
        if (count != n) return false;

        vector<int> visited(n, 0);
        int s = dfs(graph, visited, graph[0][0]);
        cout << s << endl;
        return s == n;
    }
};


class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> graph(n + 1); 
        for (auto i : edges){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }

        vector<vector<int>> times(n + 1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 1});
        times[1].push_back(0);

        while (!pq.empty()){
            auto cur = pq.top();
            pq.pop();

            if (cur.second == n && times[n].size() > 1) return times[n][1];
            for (auto n : graph[cur.second]){
                int ntime;
                if ((cur.first / change) % 2 ) ntime = time + (cur.first / change + 1) * change;
                else ntime = time + cur.first;
                if (!times[n].empty() && ntime == times[n][0] || times[n].size() > 1) continue;
                pq.push({ntime, n});
                times[n].push_back(ntime);
            }
        }
        return 0;
    }
};

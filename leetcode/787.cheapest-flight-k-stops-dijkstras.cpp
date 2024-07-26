class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // just dijkstras with k condition, k matters more than shortest
        vector<vector<pair<int, int>>> graph(n);
        for (auto i : flights){
            graph[i[0]].push_back({i[1], i[2]});
        }

        queue<vector<int>> pq;
        vector<int> dist(n, 1e9);
        pq.push({0, src, 0});
        while (!pq.empty()){
            auto cur = pq.front();
            pq.pop();
            cout << cur[0] << cur[1] << cur[2] << endl;
            for (auto n : graph[cur[1]]){
                if (cur[2] + 1 > k + 1) continue; // check k
                if (cur[0] + n.second < dist[n.first]){ 
                    pq.push({dist[n.first] = cur[0] + n.second, n.first, cur[2] + 1});
                }
            }
        }
        return (dist[dst] == 1e9) ? -1 : dist[dst];
    }
};

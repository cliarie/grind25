#include <queue>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
       // probably bfs ? O(n^2) then find best path using dijkstras?
        // populate for 
        int n = grid.size();
        queue<pair<int, int>> q;
        vector<vector<int>> safenum(n, vector<int> (n, -1));
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                if (grid[i][j]){
                    safenum[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        int dist = 0;
        while (!q.empty()){
            int curr = q.front().first, curc = q.front().second;
            q.pop();
            for (auto d : dirs){
                int nr = curr + d.first, nc = curc + d.second;
                if (nr >= 0 && nc >= 0 && nr < n && nc < n && safenum[nr][nc] == -1){
                    safenum[nr][nc] = safenum[curr][curc] + 1;
                    q.push({nr, nc});
                }
            }
        }
        
        // dijk take greatest keep track of min in path
        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({safenum[0][0], {0,0}});
        int ans = 1e9;
        while (!pq.empty()){
            int curr = pq.top().second.first, curc = pq.top().second.second, safe = pq.top().first;
            pq.pop();
            ans = min(ans, safe);
            if (curr == n - 1 && curc == n - 1) return ans;
            for (auto d : dirs){
                int nr = curr + d.first, nc = curc + d.second;
                if (nr >= 0 && nc >= 0 && nr < n && nc < n && safenum[nr][nc] != -1){
                    pq.push({safenum[nr][nc], {nr, nc}});
                    safenum[nr][nc] = -1;
                }
            }
        }
        return 0;
    }
};

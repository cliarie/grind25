#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> visited(n, vector<int>(m, -1));

        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if (grid[i][j]==2){
                    q.push({i, j});
                    visited[i][j] = 0;
                }
            }
        }

        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (!q.empty()){
            int curr = q.front().first, curc = q.front().second;
            q.pop();
            for (auto &d : dir){
                int nr = curr + d.first, nc = curc + d.second;
                if (nr >= 0 && nc >= 0 && nr < n && nc < m && visited[nr][nc] == -1 && grid[nr][nc] == 1){
                    q.push({nr, nc});
                    visited[nr][nc] = visited[curr][curc] + 1;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if (visited[i][j] == -1 && grid[i][j] == 1) return -1;
                if (visited[i][j] != -1) ans = max(ans, visited[i][j]);
            }
        }
        return ans;
    }
};

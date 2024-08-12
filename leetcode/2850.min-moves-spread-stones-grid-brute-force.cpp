#include <vector>
using namespace std;
class Solution {
public:
    int solve(vector<vector<int>>& grid){
        bool dn = 0;
        for (int i = 0; i < 3; ++i){
            for (int j = 0; j < 3; ++j){
                if (grid[i][j] == 0) {dn = 1;break;}
            }
        }

        if (!dn) return 0;

        int ans = 1e9;
        for (int i = 0; i < 3; ++i){
            for (int j = 0; j < 3; ++j){
                if (grid[i][j] == 0){
                    for (int k = 0; k < 3; ++k){
                        for (int l = 0; l < 3; ++l){
                            if (grid[k][l] > 1){
                                grid[k][l]--;
                                grid[i][j]++;
                                int dist = abs(j-l) + abs(i-k);
                                ans = min(ans, dist + solve(grid));
                                grid[k][l]++;
                                grid[i][j]--;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
    int minimumMoves(vector<vector<int>>& grid) {

        return solve(grid);
    }
};

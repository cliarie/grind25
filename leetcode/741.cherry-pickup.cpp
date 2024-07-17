#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    int n;
    int solve(vector<vector<int>> &grid, vector<vector<vector<int>>> &dp, int r1, int c1, int r2)
    {
        int c2 = r1 + c1 - r2;

        if (r1 >= n || r2 >= n || c1 >= n || c2 >= n)
            return -9999; // out of range
        if (grid[r1][c1] == -1 || grid[r2][c2] == -1)
        {
            dp[r1][c1][r2] = -9999;
            return -999;
        }
        if (dp[r1][c1][r2] != -2)
            return dp[r1][c1][r2];

        if (r1 == n - 1 && c1 == n - 1 || r2 == n - 1 && c2 == n - 1)
        {
            dp[r1][c1][r2] = grid[n - 1][n - 1];
            return grid[n - 1][n - 1];
        }

        int cherries = 0;
        if (r1 == r2 && c1 == c2)
            cherries += grid[r1][c1];
        else
            cherries += grid[r1][c1] + grid[r2][c2];

        int best = -9999999;
        best = max(best, solve(grid, dp, r1, c1 + 1, r2));
        best = max(best, solve(grid, dp, r1, c1 + 1, r2 + 1));
        best = max(best, solve(grid, dp, r1 + 1, c1, r2));
        best = max(best, solve(grid, dp, r1 + 1, c1, r2 + 1));

        // int best = 0;
        // if (r1 < n && c1 + 1 < n && r2 < n) best = max(best, dp[r1][c1 + 1][r2]);
        // if (r1 < n && c1 + 1 < n && r2 + 1 < n) best = max(best, dp[r1][c1 + 1][r2 + 1]);
        // if (r1 + 1 < n && c1 < n && r2 < n) best = max(best, dp[r1 + 1][c1][r2]);
        // if (r1 + 1 < n && c1 < n && r2 + 1 < n) best = max(best, dp[r1 + 1][c1][r2 + 1]);
        // int best = max(dp[r1][c1 + 1][r2], dp[r1][c1 + 1][r2 + 1]);
        // best = max(best, dp[r1 + 1][c1][r2]);
        // best = max(best, dp[r1 + 1][c1][r2 + 1]);
        dp[r1][c1][r2] = cherries + best;
        cout << r1 << " " << c1 << " " << r2 << " " << c2 << " " << dp[r1][c1][r2] << endl;
        return dp[r1][c1][r2];
    }

    int cherryPickup(vector<vector<int>> &grid)
    {
        n = grid.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -2)));

        solve(grid, dp, 0, 0, 0);

        if (dp[n - 1][n - 1][n - 1] < 0)
            return 0;
        return dp[0][0][0];
    }
};
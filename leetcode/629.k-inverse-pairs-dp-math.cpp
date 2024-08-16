#include <vector>
using namespace std;
const int MOD = 1e9 + 7;

class Solution {
public:
    int kInversePairs(int n, int k) {
        // dp[n][k] nooo it's not pascals :(
        // dp[n][k] = dp[n - 1][k] + dp[n - 1][k - 1] + .. + dp[k - n + 1]
        // sliding window / prefix sum esque ?
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        for (int i = 1; i <= n; ++i){
            for (int j = 0; j <= k; ++j){
                if (j == 0) dp[i][j] = 1;
                else{
                    for (int l = 0; l <= min(j, i - 1); ++l)
                    dp[i][j] =(dp[i][j] + dp[i - 1][j - l]) % MOD;
                }
            }
        }
        return dp[n][k];
    }
};

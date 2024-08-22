#include <vector>
using namespace std;
#define ll long long

class Solution {
public:
    const int MOD = 1e9 + 7;
    int rearrangeSticks(int n, int k) {
        vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, 0));

        // for (int i = 1; i <= n; ++i) {
        //     dp[i][1] = 1;
        //     if (i <= k) dp[i][i] = 1;
        // }
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= min(k, i); ++j){
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] * (i - 1)) % MOD;
            }
        }

        return dp[n][k];
    }
};

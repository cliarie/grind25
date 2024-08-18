#include <vector>
using namespace std;
#define ll long long
class Solution {
public:
    const int MOD = 1e9 + 7;

    int numMusicPlaylists(int n, int goal, int k) {
        // choose existing song or new song from unused
        // options = choose existing + choose unused;
        vector<vector<ll>> dp(goal + 1, vector<ll>(n + 1, 0));

        dp[0][0] = 1; // one way to choose
        for (int i = 1; i <= goal; ++i){
            for (int j = 1; j <= n; ++j){
                dp[i][j] = (dp[i - 1][j - 1] * (n - j + 1)) % MOD;
                if (j > k) dp[i][j] = (dp[i][j] + dp[i - 1][j] * (j - k)) % MOD; // can choose old song now
            }
        }
        return dp[goal][n];
    }
};

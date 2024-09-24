#define ll long long
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        ll n = amount + 1;
        vector<ll> dp(n, INT_MAX);
        dp[0] = 0;
        sort(coins.begin(), coins.end());

        for (int i = 0; i < n; ++i){
            for (auto c : coins){
                if (i - c >= 0)
                    dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
        if (dp[amount] == INT_MAX) return -1;
        return dp[amount];
    }
};

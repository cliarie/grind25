#include <iostream>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
       // dp[i][0] no stock, dp[i][1] have stock, dp[i][2] = cooldown
       int n = prices.size();
       vector<vector<int>> dp(n + 1, vector<int>(3, 0));
       dp[0][0] = 0;
       dp[0][1] = -prices[0];
       dp[0][2] = -1e9;
       for (int i = 1; i <= n; ++i){
        dp[i][0] = max(dp[i - 1][2], dp[i - 1][0]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i - 1]);
        dp[i][2] = dp[i - 1][1] + prices[i - 1];
       } 
       int ans = max(max(dp[n][0], dp[n][1]), dp[n][2]);
       for (auto i : dp) cout << i[0] << " " << i[1] << " " << i[2] << endl;
       return ans;
    }
};

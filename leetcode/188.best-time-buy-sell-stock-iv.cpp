inline const auto optimize = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return 0;
}();

class Solution {
public:
    // two options: max profit of doing k selling, max profit from doing k buying 
    // can only sell after buy, buy after sell, keep track of k in buy so only increment k when we bought
    // dp[i][0] is max profit of buying with i transactions
    // dp[i][1] is max profit of selling with i transactions
    // 
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> dp(k + 1, vector<int>(2, 0));

        for (int i = 0; i <= k; ++i) dp[i][0] = -1e9; // make it worth it to buy the first one or else we sell first which doesn't make sense
        for (int p : prices){
            for (int i = k; i >= 1; --i){ // reverse in case of overrides dp[i][0] depends on dp[i - 1][1] so must preserve value of dp[i - 1][1] and vice versa
                dp[i][0] = max(dp[i][0], dp[i - 1][1] - p); // buy profit is max of dont buy this one/ buy this one, can only buy after selling
                dp[i][1] = max(dp[i][1], dp[i][0] + p); // max profit of selling k 
            }
        }
        return max(dp[k][0], dp[k][1]);
    }
};

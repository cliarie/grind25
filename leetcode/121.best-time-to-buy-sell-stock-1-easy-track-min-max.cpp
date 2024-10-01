class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini = 1e9, profit = 0;
        for (int i = 0; i < n; ++i){
            if (prices[i] > mini){
                profit = max(prices[i] - mini, profit);
            }
            else{
                mini = prices[i];
            }
        }
        return profit;
    }
};

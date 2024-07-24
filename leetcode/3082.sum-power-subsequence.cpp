class Solution {
public:
    const int mod = 1e9 + 7;
    int pow(int x, int y){
        int ans = 1;
        while (y){
            ans = ans * x % mod;
            y--;
        }
        return ans;
    }
    int sumOfPower(vector<int>& nums, int k) {
        // sum of total # subseq that sum to k
        // count subset == k -> 2d dp pick not pick
        // first find subsets that sum to k
        // each set of sum k contributes ?? to total, need amt of subets and size of subset..
        // ex1 subset 3 -> 4; 1,2 -> 2
        // ex2 subset 2,3 -> 2; 2,3 -> 2
        // len 1 contributes 4; len 2 contributes 2; 
        // 1 + 2^(total-len) (pick not pick everything else thats not subset)
        // dp[length][sum] ?
        int n = nums.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));

        dp[0][0] = 1;
        for(int pos = 1 ; pos <= n ; pos++){
            for(int len = pos ; len >= 1 ; len--){
                for(int sum = nums[pos-1] ; sum <= k ; sum++){
                    dp[len][sum] = (dp[len][sum] + dp[len-1][sum-nums[pos-1]] ) % mod;
                }
            }
        }
        // for (int sum = 0; sum <= k; sum++){
        //     for (int len = n; len >= 1; len--){
        //         for (int i = 0; i < n; ++i){
        //             if (sum - nums[i] >= 0 && len - 1 >= 0)
        //             dp[sum][len] += dp[sum - nums[i]][len - 1];
        //         }
        //     }
        // }

        // iterate through dp[k]
        long long total = 0;
        for (int i = 1; i <= n; ++i){
            cout << dp[i][k] << endl;
            total += (dp[i][k] * (int)(pow(2, n - i))) % (mod);
        }
        int ans = total % (mod);
        
        return ans;
    }
};

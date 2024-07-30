const int inf = 1e9;

class Solution {
public:
    int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) {
        int n = nums1.size();
        vector<pair<int, int>> nums;
        for (int i = 0; i < n; ++i){
            nums.push_back({nums2[i], nums1[i]});
        }
        sort(nums.begin(), nums.end());

        vector<int> fs(n + 1, 0), ss(n + 1, 0);
        for (int i = 1; i <= n; ++i){
            fs[i] = fs[i - 1] + nums[i - 1].second;
            ss[i] = ss[i - 1] + nums[i - 1].first;
        }
        if (fs[n] <= x) return 0;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1)); // track index and # operations and store total sum

        // if j is zero, don't do any operations
        for (int i = 1; i <= n; ++i){
            dp[i][0] = fs[i];
            for (int j = 1; j <= i; ++j){ // max ops capped at n
                // choose / don't choose
                // prev + everything incremented minus zeroed initial and incremented amt
                int totalbf = nums[i - 1].second + nums[i - 1].first * j;

                dp[i][j] = (i > j) ? min(dp[i - 1][j - 1] + ss[i - 1], dp[i - 1][j] + totalbf) : dp[i - 1][j - 1] + ss[i - 1];
                if (i == n && dp[i][j] <= x) return j;
            }
        }

        return -1;
    }
};

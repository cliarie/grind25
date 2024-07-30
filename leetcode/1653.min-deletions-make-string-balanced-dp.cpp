const int inf = 1e9;
class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int> dp(n + 1,inf);
        int b = 0;
        dp[0] = 0;
        for (int i = 1; i <= n; ++i){
            b += (s[i - 1] == 'b'); // num b's before it (keep a's delete b's at this index)
            dp[i] = dp[i - 1];
            if (s[i - 1] == 'a')
            dp[i] = min(dp[i - 1] + 1, b); // (treat last as last a to keep)
        } 
        return dp[n];
    }
};

/*
 * @lc app=leetcode id=3104 lang=cpp
 *
 * [3104] Find Longest Self-Contained Substring
 */
#include <string>
#include <map>
#include <iostream>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; ++i)
        {
            dp[i][0] = true;
            for (int j = 1; j <= i; ++j)
            {
                if (p[j - 1] != '*')
                    dp[i][0] = false;
            }
        }

        for (int j = 0; j <= n; ++j)
        {
            dp[0][j] = 0;
        }

        dp[0][0] = true;

        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (p[i - 1] == '?' || p[i - 1] == s[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[i - 1] == '*')
                {   // anything after it is valid
                    // 2 situations : * matches no characters, * matches >=1 characters
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
                else
                    dp[i][j] = false;
            }
        }

        return dp[m][n];
    }
};
// @lc code=end

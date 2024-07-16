/*
 * @lc app=leetcode id=3104 lang=cpp
 *
 * [3104] Find Longest Self-Contained Substring
 */
#include <string>
#include <map>
using namespace std;
// @lc code=start
class Solution
{
public:
   bool check(vector<vector<int>> &freq, int li, int ri)
   {
      return true;
   }
   int maxSubstringLength(string s)
   {
      map<int, int> leftmost, rightmost;
      vector<vector<int>> freq(s.length(), vector<int>(26, 0));

      freq[0][int(s[0]) - 'a'] = 1;
      leftmost[int(s[0]) - 'a'] = 0;
      rightmost[int(s[0]) - 'a'] = 0;

      for (int i = 1; i < s.length(); ++i)
      {
         int c = int(s[i]) - 'a';
         if (leftmost.find(c) != leftmost.end())
         {
            leftmost[c] = i;
         }
         rightmost[int(s[i]) - 'a'] = i;
         for (int j = 0; j < 26; ++j)
         {
            freq[i][j] = freq[i - 1][j] + 1;
         }
      }

      int ans = 0;
      for (auto l : leftmost)
      {
         int li = l.second;
         for (auto r : rightmost)
         {
            int ri = r.second;
            if (ri == s.length() - 1 && li == 0 || ri < li)
            {
               continue;
            }
            // check if substring is valid
            if (check(freq, li, ri))
               ans = max(ans, (ri - li) + 1);
         }
      }
      return (ans == 0) ? -1 : ans;
   }
};
// @lc code=end

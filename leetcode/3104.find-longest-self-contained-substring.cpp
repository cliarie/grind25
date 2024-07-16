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
   bool check(vector<vector<int>> &freq, int &li, int &ri, string &s)
   {
      // cout << li << " " << ri << endl;
      // map<int, int> subfreq;
      int curfreq;
      for (int i = 0; i < 26; ++i)
      {
         if (li == 0)
            curfreq = freq[ri][i];
         else
            curfreq = freq[ri][i] - freq[li - 1][i];
         if (curfreq != 0 && curfreq != freq[s.length() - 1][i])
            return false;
      }
      // for (auto i : subfreq)
      //    cout << i.first << " " << i.second << endl;
      // for (auto i : subfreq)
      // {

      // }
      return true;
   }
   int maxSubstringLength(string s)
   {
      map<int, int> leftmost, rightmost;
      vector<vector<int>> freq(s.length(), vector<int>(26, 0));
      freq[0][s[0] - 'a'] = 1;
      leftmost[s[0] - 'a'] = 0;
      rightmost[s[0] - 'a'] = 0;

      for (int i = 1; i < s.length(); ++i)
      {
         int c = s[i] - 'a';
         if (leftmost.find(c) == leftmost.end())
         {
            leftmost[c] = i;
         }
         rightmost[c] = i;
         freq[i][c]++;
         for (int j = 0; j < 26; ++j)
         {
            freq[i][j] += freq[i - 1][j];
         }
      }
      // for (auto i : leftmost)
      //    cout << i.first << " " << i.second << endl;

      // for (int i = 0; i < freq.size(); ++i)
      // {
      //    for (int j = 0; j < freq[i].size(); ++j)
      //    {
      //       cout << freq[i][j] << " ";
      //    }
      //    cout << endl;
      // }

      int ans = 0;
      for (auto l : leftmost)
      {
         int li = l.second;
         for (auto r : rightmost)
         {
            int ri = r.second;
            // cout << li << " fi " << ri << endl;
            if (ri == s.length() - 1 && li == 0 || ri < li)
            {
               continue;
            }
            // check if substring is valid
            if (check(freq, li, ri, s))
               ans = max(ans, (ri - li) + 1);
         }
      }
      return (ans == 0) ? -1 : ans;
   }
};
// @lc code=end

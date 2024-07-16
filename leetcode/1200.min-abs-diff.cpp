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
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int diff = 1e9 + 1;
        for (int i = 1; i < arr.size(); ++i)
        {
            diff = min(diff, arr[i] - arr[i - 1]);
        }

        int l = 0, r = 0;
        vector<vector<int>> ans;
        while (r < arr.size())
        {
            if (arr[r] - arr[l] == diff)
            {
                ans.push_back({arr[l], arr[r]});
                l++;
                r++;
            }
            else if (arr[r] - arr[l] > diff)
                l++;
            else
                r++;
        }
        return ans;
    }
};
// @lc code=end

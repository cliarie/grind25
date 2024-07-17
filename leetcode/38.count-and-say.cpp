#include <string>
#include <iostream>
using namespace std;
class Solution
{
public:
    string rle(string &s)
    {
        string cur(1, s[0]), ans = "";
        int count = 1;
        for (int i = 1; i < s.length(); ++i)
        {
            if (s[i] == s[i - 1])
            {
                count++;
                continue;
            }
            else
            {
                ans += "" + to_string(count) + cur;
                cur = "";
                cur.append(1, s[i]);
                count = 1;
            }
        }
        ans += "" + to_string(count) + cur;
        return ans;
    }
    string countAndSay(int n)
    {
        string cur = "1";
        for (int i = 1; i < n; ++i)
        {
            cout << cur << endl;
            cur = rle(cur);
        }
        return cur;
    }
};
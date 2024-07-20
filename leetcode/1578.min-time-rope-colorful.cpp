#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int n = colors.length();
        int l = 0, r = 0, segtotal = 0, segmax = 0, time = 0;
        while (r != n)
        {
            if (colors[r] == colors[l])
            {
                segmax = max(segmax, neededTime[r]);
                segtotal += neededTime[r];
                r++;
            }
            else
            {
                time += segtotal - segmax;
                l = r;
                segmax = 0;
                segtotal = 0;
            }
        }
        time += segtotal - segmax;
        return time;
    }
};

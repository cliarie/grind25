/*
 * @lc app=leetcode id=3104 lang=cpp
 *
 * [3104] Find Longest Self-Contained Substring
 */
#include <string>
#include <stack>
#include <iostream>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool reachingPoints(int sx, int sy, int tx, int ty)
    {
        while (tx >= sx && ty >= sy)
        {
            cout << tx << " " << ty << endl;

            if (tx == sx && ty == sy)
                return true;
            if (tx > ty)
            {
                int n = (tx - sx) / ty;
                if (n == 0)
                    return false;
                if (tx % ty >= sx)
                    tx = tx % ty;
                else
                    tx = tx - n * ty;
                // we want new tx = tx - n*ty and it must be >= sx;
                // so tx - n*ty >= sx; so n >= (tx - sx) / ty
            }
            else if (ty > tx)
            {
                int n = (ty - sy) / tx;
                if (n == 0)
                    return false;
                if (ty % tx >= sy)
                    ty = ty % tx;
                else
                    ty = ty - n * tx;
            }
            else
                return (tx == sx && ty == sy);
            // if (tx > sx && tx - ty >= sx){
            //     if (tx - ty == sx) tx = tx - ty;
            //     else if (tx > ty && tx % ty != 0) tx = tx % ty;
            //     else tx = tx - ty;
            //     if (tx == sx && ty == sy) return true;
            // }
            // else if (ty > sy && ty - tx >= sy) {
            //     if (ty - tx == sy) ty = ty - tx;
            //     else if (ty > tx && ty % tx != 0) ty = ty % tx;
            //     else ty = ty - tx;
            //     if (tx == sx && ty == sy) return true;
            // }
            // else return false;
        }
        return false;
    }
};
// @lc code=end

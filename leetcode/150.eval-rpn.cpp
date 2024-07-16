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
    bool isoperation(string c)
    {
        return (c == "+" || c == "-" || c == "*" || c == "/");
    }

    int eval(stack<int> &s, string op)
    {
        int t1 = s.top();
        s.pop();
        int t2 = s.top();
        s.pop();
        if (op == "+")
            return t2 + t1;
        else if (op == "-")
            return t2 - t1;
        else if (op == "/")
            return t2 / t1;
        else
            return t2 * t1;
    }

    int evalRPN(vector<string> &tokens)
    {
        stack<int> s;

        int ans = 0;
        for (auto &t : tokens)
        {
            if (isoperation(t))
            {
                s.push(eval(s, t));
            }
            else
                s.push(stoi(t));
        }
        return s.top();
    }
};
// @lc code=end

#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    int largestInteger(int num)
    {
        vector<long long> digits;
        while (num != 0)
        {
            digits.push_back(num % 10);
            num /= 10;
        }
        reverse(digits.begin(), digits.end());

        priority_queue<long long> evens, odds;
        for (auto i : digits)
        {
            if (i % 2 == 0)
                evens.push(i);
            else
                odds.push(i);
        }

        vector<long long> ans = digits;
        for (int i = 0; i < digits.size(); ++i)
        {
            if (digits[i] % 2 == 0)
            {
                ans[i] = evens.top();
                evens.pop();
            }
            else
            {
                ans[i] = odds.top();
                odds.pop();
            }
        }
        long long largest = 0;
        long long n = 1;
        for (int i = ans.size() - 1; i >= 0; --i)
        {
            largest += ans[i] * n;
            n *= 10;
        }

        return largest;
    }
};
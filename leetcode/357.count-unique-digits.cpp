#include <vector>
using namespace std;
class Solution
{
public:
    int countNumbersWithUniqueDigits(int n)
    {
        vector<int> unique(8 + 1, 0);
        unique[0] = 1;
        unique[1] = 9;
        int dig = 9;
        for (int i = 2; i <= n; ++i)
        {
            unique[i] = unique[i - 1] * dig;
            dig--;
        }
        int ans = 0;
        for (int i = 0; i <= n; ++i)
            ans += unique[i];
        return ans;
    }
};
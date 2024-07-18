#include <algorithm>
using namespace std;
class Solution
{
public:
    int minOperations(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        int i = 1;
        while (i * 2 < n)
            i *= 2;
        int ldiff = n - i;
        int udiff = i * 2 - n;
        return min(minOperations(ldiff) + 1, minOperations(udiff) + 1);
    }
};
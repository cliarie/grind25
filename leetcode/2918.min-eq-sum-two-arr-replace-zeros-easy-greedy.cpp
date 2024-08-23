#include <vector>
#include <numeric>
using namespace std;
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long s1 = accumulate(nums1.begin(), nums1.end(), 0LL), s2 = accumulate(nums2.begin(), nums2.end(), 0LL);
        long long z1 = count(nums1.begin(), nums1.end(), 0LL), z2 = count(nums2.begin(), nums2.end(), 0LL);

        if (!z1 && ((s1 + z1) < (s2 + z2)) || !z2 && ((s2 + z2) < (s1 + z1))) return -1;

        return max(s1 + z1, s2 + z2);

    }
};

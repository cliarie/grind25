#include <vector>
using namespace std;
class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n);
        long long conver = nums[0];
        ans[0] = nums[0] * 2;
        int amax = nums[0];
        for (int i = 1; i < n; ++i){
            amax = max(nums[i], amax);
            conver = nums[i] + amax;
            ans[i] = ans[i - 1] + conver;
        }
        return ans;
    }
};

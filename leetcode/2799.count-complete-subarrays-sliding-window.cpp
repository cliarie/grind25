#include <map>
#include <vector>
using namespace std;
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (auto &e : nums) freq[e] = 0;

        int n = nums.size();
        int distinct = 0, ans = 0, l = 0, r = 0;
        while(r < n){
            if (!freq[nums[r]]) distinct++;
            freq[nums[r]]++;
            while(distinct == freq.size()){
                ans += n - r;
                freq[nums[l]]--;
                if (!freq[nums[l]]) distinct--;
                l++;
            }
            r++;
        }
        return ans;
    }
};

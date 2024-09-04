#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int n = nums.size();
        // nlogn
        unordered_map<int, int> seen; seen[0]++;
        int cur = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i){
            cur += nums[i];
            if (seen.find(cur - k) != seen.end()){
                ans+=seen[cur-k];
            }
            seen[cur]++;
        }
        return ans;
    }
};

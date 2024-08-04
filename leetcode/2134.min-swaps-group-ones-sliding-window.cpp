class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size(), swaps = n;
        int ones = accumulate(nums.begin(), nums.end(), 0);
        if (!ones) return 0;

        int l = 0, r = ones, cur = accumulate(nums.begin(), nums.begin() + ones, 0);        
        for (; r < 2 * n; ++r){
            if (r >= ones && nums[(r - ones)%n] == 1) cur--;
            if (nums[r%n] == 1) cur++;
            swaps = min(swaps, ones - cur);
        }

        return swaps;

    }
};

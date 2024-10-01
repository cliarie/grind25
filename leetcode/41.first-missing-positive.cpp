#include <iostream>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // smallest positive must be between 1 to n or else n + 1
        int n = nums.size();
        for (int i = 0; i < n; ++i){
            while(nums[i] < n && nums[i] >= 0 && nums[i] != i && nums[i] != nums[nums[i]]){
                swap(nums[i], nums[nums[i]]);
            }
        }

        for (int i = 1; i < n; ++i){
            if (nums[i] != i) return i;
        }
        if (nums[0] != n) return n;
        return n + 1;
    }
};

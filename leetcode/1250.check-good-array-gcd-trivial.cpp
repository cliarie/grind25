class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int gcd = nums[0];
        for (auto num: nums){
            gcd = __gcd(num, gcd);
        }
        return gcd == 1;
    }
};

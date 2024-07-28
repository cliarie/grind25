class Solution {
public:
    long long largestEvenSum(vector<int>& nums, int k) {
        // order doesn't matter since addition O(n)
        sort(nums.begin(), nums.end(), greater<long long>());
        long long sum = 0;
        sum = accumulate(nums.begin(), nums.begin() + k, sum);
        if (sum%2 == 0) return sum;
        // sum is odd: change out smallest odd for even or smallest even for odd
        long long so = -1, se = -1, lo = -1, le = -1;
        for (int i = k - 1; i >= 0; --i){
            if (so != -1 && se != -1) break;
            if (so == -1 && nums[i]%2 == 1) so = nums[i];
            else if (se == -1 && nums[i]%2 == 0) se = nums[i];
        }
        for (int i = k; i < nums.size(); ++i){
            if (lo != -1 && le != -1) break;
            if (lo == -1 && nums[i]%2==1) lo = nums[i];
            else if (le == -1 && nums[i]%2==0) le = nums[i];
        }
        long long temp = -1;
        if (le != -1 && so != -1) temp = sum - so + le;
        if (lo != -1 && se != -1) temp = max(temp, sum - se + lo);
        return (temp != -1) ? temp : -1;
    }
};

class Solution {
public:
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> c(n);
        for (int i = 0; i < n; ++i){
            c[i] = nums1[i] - nums2[i];
        }
        sort(c.begin(), c.end());

        // a[i] - b[i] > -(a[j]-b[j])
        long long ans = 0;
        for (int i = 0; i < n; ++i){
            auto it = upper_bound(c.begin() + i + 1, c.end(), -c[i]);
            ans += c.end() - it;
        }
        return ans;
    }
};

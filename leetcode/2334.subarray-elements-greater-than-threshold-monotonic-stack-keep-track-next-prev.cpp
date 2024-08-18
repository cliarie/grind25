#include <vector>
using namespace std;
class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        // assume index i is the smallest then find subarrays based off that
        int n = nums.size();
        vector<int> st, next(n, n), prev(n, -1); // keep track of next/prev smallest element

        for (int i = 0; i < n; ++i){
            while (!st.empty() && nums[st.back()] > nums[i]){
                next[st.back()] = i;
                st.pop_back();
            }
            st.push_back(i);
        }

        st.clear();

        for (int i = n - 1; i >= 0; --i){
            while(!st.empty() && nums[st.back()] > nums[i]){
                prev[st.back()] = i;
                st.pop_back();
            }
            st.push_back(i);
        }

        // for (auto i : next) cout << i << " ";
        // cout << endl;
        // for (auto i : prev) cout << i << " ";
        // cout << endl;

        for (int i = 0; i < n; ++i){
            long long k = (next[i] - 1) - (prev[i] + 1) + 1;
            if (nums[i] * k > threshold) return k;
        }

        return -1;
    }
};

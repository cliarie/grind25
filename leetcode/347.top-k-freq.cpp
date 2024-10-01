class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        unordered_map<int, int> m;
        for (auto n : nums) m[n]++;
        for (auto [key, val] : m){
            pq.push({val, key});
        }
        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};

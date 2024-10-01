class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<int> indices;
        indices.push(0);
        for (int i = 1; i < n; ++i){
            while(!indices.empty() && temperatures[i] > temperatures[indices.top()]){
                ans[indices.top()] = i - indices.top();
                indices.pop();
            }
            indices.push(i);
        }
        while(!indices.empty()){
            ans[indices.top()] = 0;
            indices.pop();
        }
        return ans;
    }
};

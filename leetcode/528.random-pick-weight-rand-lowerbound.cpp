class Solution {
public:
    vector<int> weights;
    Solution(vector<int>& w) {
        weights = vector<int>(w.size(), 0);
        for (int i = 0; i < weights.size(); ++i){
            weights[i] = (i == 0) ? w[i] : w[i] + weights[i - 1];
        }
    }

    int pickIndex() {
        float randNum = ((float) rand()) / RAND_MAX;
        randNum *= weights.back();
        auto it = lower_bound(weights.begin(), weights.end(), randNum);
        return it - weights.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

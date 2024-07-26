class Solution {
public:
    vector<long long> minimumCosts(vector<int>& regular, vector<int>& express, int expressCost) {
        int n = regular.size();
        vector<long long> expdp(n + 1), regdp(n + 1), costdp(n);
        expdp[0] = expressCost;

        for (int i = 1; i <=n; ++i){
            regdp[i] = min(regdp[i - 1] + regular[i - 1], expdp[i - 1] + min(regular[i - 1], express[i - 1]));
            expdp[i] = min(expdp[i - 1] + express[i - 1], regdp[i - 1] + expressCost + express[i - 1]);
            costdp[i - 1] = min(regdp[i], expdp[i]);
        }
        return costdp;
    }
};

class Solution {
public:
    vector<int> minOperations(string boxes) {
        // o(n)
        int n = boxes.size();

        vector<int> rpref(n, 0), lpref(n, 0);
        int lcount = 0;
        for (int i = 1; i < n; ++i){
            lcount += boxes[i - 1] - '0'; // num ones on the left
            lpref[i] = lpref[i - 1] + lcount;
        }
        int rcount = 0;
        for (int i = n - 2; i >= 0; --i){
            rcount += boxes[i + 1] - '0';
            rpref[i] = rpref[i + 1] + rcount;
        }
        for (auto i : rpref) cout << i << " " ;
        cout << endl;
        vector<int> ans(n, 0);
        for (int i = 0; i < n; ++i){
            ans[i] = rpref[i] + lpref[i];
        }
        return ans;
    }
};

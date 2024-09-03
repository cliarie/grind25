class Solution {
public:
    typedef long long ll;
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();
        ll l = 0, u = 0;
        ll num = 0;
        for (int i = 0; i < n; ++i){
            num += differences[i];
            l = min(l, num);
            u = max(u, num); 
        }
        int ans;
        if (l == u) ans = upper - lower - abs(u) + 1;
        else ans = upper - lower - (u - l) + 1;
        cout << ans << " " << l << " " << u << endl;
        if (ans >= 0) return ans;
        return 0;
    }
};

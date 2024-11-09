#include <iostream>
#include <vector>
using namespace std;
/*
4 2 3 5 1 -> 1 5 4 2 3 -> 1 2 3 is lis ->
4 5 1 3 2 -> 3 5 4 1 2

1 2 3 4 -> 1 2 3 4 -> 1 2 3 4
1 2 4 3 -> 1 2 3 4
*/
int main(){
    #ifdef LOCAL_TESTING
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<int> a(n), b(n), c(n), d(n); // a[d[i]] = b[i]
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            a[i]--;
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            b[i]--;
        }

        // populate c, c[i] = index mapping of b
        for (int i = 0; i < n; ++i){
            c[b[i]] = i;
        }
        for (int i = 0; i < n; ++i){
            d[i] = c[a[i]];
        }

        // find lics of d
        vector<int> ans;
        ans.push_back(d[0]);
        for (int i = 1; i < n; ++i){
            if (d[i] > ans.back()){
                ans.push_back(d[i]);
            } else {
                int idx = lower_bound(ans.begin(), ans.end(), d[i]) - ans.begin();
                ans[idx] = d[i];
            }
        }
        cout << 2 * n - 2*ans.size() << endl;
    }
}

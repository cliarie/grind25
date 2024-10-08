#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main(){
    #ifdef LOCAL_TESTING
       freopen("../input.txt", "r", stdin);
       freopen("../output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<ll> pos, neg;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            if (x > 0) pos.push_back(x);
            else neg.push_back(x);
        }
        sort(pos.begin(), pos.end(), greater<int>());
        sort(neg.begin(), neg.end());
        ll ans = 0;
        if (!pos.empty()){
            for (int i = 0; i < pos.size(); i += k){
                ans += pos[i]*2;
            }
        }
        if (!neg.empty()){
            for (int i = 0; i < neg.size(); i += k){
                ans += abs(neg[i])*2;
            }
        }

        ans -= max(pos.empty() ? 0 : pos[0], neg.empty() ? 0 : abs(neg[0]));
        cout << ans << endl;
    }
}

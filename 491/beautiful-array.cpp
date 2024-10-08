#include <iostream>
#include <vector>
#include <queue>
#define ll long long
using namespace std;

int count_twos(ll x){
    if(x == 0) return 0;
    return __builtin_ctzll(x);
}

int main(){
    #ifdef LOCAL_TESTING
       freopen("../input.txt", "r", stdin);
       freopen("../output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<ll> arr(n);
        for (auto &i : arr) cin >> i;

        vector<ll> gains; gains.reserve(n);
        int total_twos = 0;
        for (auto i = 0; i < n; ++i){
            ll original = arr[i];
            ll multiplied = arr[i] * (i + 1);

            ll twos_original = count_twos(original);
            ll twos_multiplied = count_twos(multiplied);

            total_twos += twos_original;

            if (twos_multiplied > twos_original){
                gains.push_back(twos_multiplied - twos_original);
            }
        }
        // cout << n <<  " n and total " << total_twos << " " << pq.empty() << endl;
        sort(gains.begin(), gains.end(), greater<ll>());

        ll modified = 0;
        for (auto gain : gains){
            if (total_twos >= n) break;
            total_twos += gain;
            modified++;
        }

        if (total_twos < n) cout << -1 << endl;
        else cout << modified << endl;
    }
}

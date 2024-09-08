#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

bool check(ll mid, vector<ll> &arr, ll h){
    ll ans = 0;
    for (int i = 0; i < arr.size(); ++i){
        if (i != arr.size() - 1) ans += min(mid, arr[i + 1] - arr[i]);
        else ans += mid;
    }
    return ans >= h;
}

int main(){
    #ifdef LOCAL_TESTING
       freopen("../input.txt", "r", stdin);
       freopen("../output.txt", "w", stdout);
    #endif
    int t; cin >> t;
    for (int i = 0; i < t; ++i){
        ll n, h; cin >> n >> h;
        ll kmax = h-n+1, kmin = 1;
        vector<ll> arr(n);
        for (auto &num: arr) cin >> num;
        sort(arr.begin(), arr.end());

        while(kmax >= kmin){
            ll mid = (kmax + kmin) / 2;
            if (check(mid, arr, h)){
                kmax = mid - 1;
            }
            else{
                kmin = mid + 1;
            }
        }
        cout << kmin << endl;
    }

}

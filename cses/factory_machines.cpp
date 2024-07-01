#include <iostream>
#include <vector>
#define ll long long
const ll MAXVAL = 1e18;

using namespace std;

bool check(ll mid, ll n, ll t, vector<ll>& arr){
    ll sum = 0;
    for (int i = 0; i < n; ++i){
        sum += (mid / arr[i]);
        if (sum >= t) return true;
    }
    return false;
}
int main(){
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    ll n, t; cin >> n >> t;
    vector<ll> arr(n, 0);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    sort(arr.begin(), arr.end());

    ll l = 0, r = MAXVAL;
    while (l <= r){
       //cout << l << " " << r << endl;
        ll mid = (l + r)/2;
        if (l == r) break;
        if (check(mid, n, t, arr)){
            r = mid;
        }
        else l = mid + 1;
    }
    cout << l << endl;
}

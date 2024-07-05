#include <iostream>
#include <vector>
#include <map>
#define ll long long
using namespace std;

/*
map prefix sum to freq:
prefix[0...i] : 3 -> P : 3
prefix[0...j] : 2 -> P - x : 2
P - (P - X) = X -> subarray [i, j] counts
*/
int main(){
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    int n, x; cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    map<ll, ll> prefix; ll total = 0, ans = 0;
    prefix[0] = 1;
    for (int i = 0; i < n; ++i){
        total += arr[i];
        //for (auto p : prefix) cout << p.first << " " << p.second << " "; cout << endl;
        ans += prefix[total - x];
        prefix[total]++;
        //if (x != 0 && total - x == 0) ans++;
    }
    cout << ans << endl;
}

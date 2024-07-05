#include <iostream>
#include <vector>
#include <map>
#define ll long long
using namespace std;

/*
maps prefix mod n to freq? similar to subarray sums
arr[0..i] % n: 2 -> R1 : 2
arr[0..j] % n: 3 -> R2 : 4
if R1 == R2 then arr[j..i] is divisible
*/
int main(){
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    map<ll, ll> prefix;
    ll total = 0, ans = 0;
    prefix[0] = 1;
    for (int i = 0; i < n; ++i){
       // for (auto x : prefix) cout << x.first << " " << x.second << endl;
        total = (total + arr[i]) % n;
        //cout << total << endl;
        if (total < 0) total += n;
        ans += prefix[total];
        prefix[total]++;
    }
    cout << ans << endl;
}

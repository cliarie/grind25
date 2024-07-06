#include <iostream>
#include <vector>
#include <map>
#define ll long long
using namespace std;

int main(){
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    ll n, k; cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    ll l = 0, r = -1, ans = 0;
    map<ll, ll> freq;
    while(r < n - 1){
        r++;
        freq[arr[r]]++;

        while (freq.size() > k) {
            if (freq[arr[l]] == 1) {
                freq.erase(arr[l]);
            }
            else freq[arr[l]]--;
            l++;
        }
        ans += r - l;

    }
    l++;
    if (k >= 0) ans += n;
    cout << ans << endl;
}

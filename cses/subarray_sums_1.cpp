#include <iostream>
#include <vector>
using namespace std;

int main(){
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    int n, x; cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    int l = 0, r = 0, total = arr[0], ans = 0;
    while (r >= l && r < n){
        //cout << r << " " << l << " " << total << " " << ans << endl;
        if (total <= x || r == l) {
            if (total == x) ans++;
            r++;
            total += arr[r];
        }
        else {
            total -= arr[l];
            l++;
        }
    }
    cout << ans << endl;
}

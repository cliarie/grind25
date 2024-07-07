#include <iostream>
#include <vector>
#define ll long long
const ll tmax = 1e15;

using namespace std;

int valid(ll mid, vector<int> &arr, ll k){
    ll total = 0;
    ll used = 0;
    for (int i = 0; i < arr.size(); ++i){
        if (total + arr[i] > mid){
            total = arr[i];
            if (total > mid) return -1;
            used++;
        }
        else total += arr[i];
    }
    if (total > mid) used++;
    // cout << used << k << endl;
    if (used == k - 1) return 0;
    if (used < k) return 1;
    return -1;
}

int main()
{
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    int n, k; cin >> n >> k;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    ll l = 0, r = tmax;
    while (r > l){
        ll mid = (l + r) / 2;
        // cout << mid << endl;
        if (valid(mid, arr, k) == 0){
            r = mid;
        }
        if (valid(mid, arr, k) == 1){
            r = mid - 1;
        }
        else if (valid(mid, arr, k) == -1){
            l = mid + 1;
        }
    }
    cout << l << endl;
}

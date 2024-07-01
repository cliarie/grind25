#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main(){
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    int n; cin >> n;
    vector<ll> arr(n, 0);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    ll sum = 0;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 1; ++i) sum += arr[i];
    if (arr[n - 1] > sum) cout << 2*arr[n - 1] << endl;
    else cout << arr[n - 1] + sum << endl;

}

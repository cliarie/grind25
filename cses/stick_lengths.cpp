#include <iostream>
#include <vector>
#define ll long long
const int INF = 1e9;

using namespace std;

int main(){
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    sort(arr.begin(), arr.end());

    ll m1 = 0, m2 = 0;
    for(int i = 0; i < n; ++i){
        m1 += abs(arr[i] - arr[n/2 - 1]);
        m2 += abs(arr[i] - arr[n/2]);
    }
    ll ans = min(m1, m2);
    cout << ans << endl;
}

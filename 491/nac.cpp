#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main(){
    #ifdef LOCAL_TESTING
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> a(n), b(n);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;

    vector<ll> dp1(n + 1, 0), dp2(n + 1, 0); // max score if we pick i from a/b respectively
    for (int i = 1; i <= n; ++i){
        dp1[i] = max(dp1[i - 1], dp2[i - 1] + a[i - 1]);
        dp2[i] = max(dp2[i - 1], dp1[i - 1] + b[i - 1]);
    }

    cout << max(dp1[n], dp2[n]) << endl;

}

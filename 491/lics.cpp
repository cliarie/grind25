#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
// longest increasing consecutive subsequence
// dp[i] = length of longest increasing consecutive subsequence ending at i
int main(){
    #ifdef LOCAL_TESTING
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    // store index of previous num in chain
    vector<int> indexmp(n + 1, -1);
    unordered_map<int, int> mp;
    vector<int> dp(n + 1, 1);

    for (int i = 1; i <= n; i++) {
        if (mp.find(a[i] - 1) != mp.end()) {
            dp[i] = dp[mp[a[i] - 1]] + 1;
            indexmp[i] = mp[a[i] - 1];
        }
        mp[a[i]] = i;
    }

    int ans = 0, index = 1;
    for (int i = 1; i <= n; i++) {
        if (dp[i] > ans) {
            ans = dp[i];
            index = i;
        }
    }

    vector<int> indices;
    while (index != -1){
        indices.push_back(index);
        index = indexmp[index];
    }

    cout << ans << endl;
    for (int i = indices.size() - 1; i >= 0; --i){
        cout << indices[i] << " ";
    }
    cout << endl;
}

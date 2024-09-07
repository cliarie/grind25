#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    #ifdef LOCAL_TESTING
       freopen("../input.txt", "r", stdin);
       freopen("../output.txt", "w", stdout);
    #endif
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), std::greater<int>());

    // can win n/2 regions
    int ans = 0;
    int canwin = n / 2;
    for (int i = 0; i < canwin; ++i){
        ans += arr[i];
    }

    for (int i = canwin; i < n; ++i){
        ans += arr[i] / 2;
    }
    cout << ans << endl;
}

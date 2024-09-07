#include <iostream>
#include <vector>
using namespace std;

int fix(int a, int b){
    int diff = b - a + 1;
    if (diff <= 0) return 0;
    if (diff % 2 == 0) return (diff)/2;
    return (diff + 1)/2;
}

int main(){
    #ifdef LOCAL_TESTING
       freopen("../input.txt", "r", stdin);
       freopen("../output.txt", "w", stdout);
    #endif

    int s, n; cin >> s >> n;
    vector<int> arr(n);
    for (auto &p : arr) cin >> p;

    int ans = 0;
    for (int i = 1; i < n; ++i){
        ans += fix(arr[i - 1] + 2, arr[i] - 2);
    }
    ans += fix(arr[n - 1] + 2, s + arr[0] - 2);
    cout << ans << endl;
}

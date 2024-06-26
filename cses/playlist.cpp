#include <iostream>
#include <vector>
using namespace std;

int main(){
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    vector<int> last(n, -1); // store last index of playlist id
    int start = 0, ans = 1;
    for (int i = 1; i < n; ++i){ // end index
        if (last[arr[i]] != -1) start = last[arr[i]] + 1;
        last[arr[i]] = i;
        ans = max(ans, i - start + 1);
    }
    cout << ans << endl;
}

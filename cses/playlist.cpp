#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    map<int, int> last; // store last index of playlist id
    int start = 0, ans = 1;
    for (int i = 0; i < n; ++i){ // end index
        if (last.find(arr[i]) != last.end()) start = max(start, last[arr[i]] + 1);
        // cout << last[arr[i]] << " d" << endl;
        ans = max(ans, i - start + 1);
        last[arr[i]] = i;

        // cout << ans << endl;
    }
    cout << ans << endl;
}

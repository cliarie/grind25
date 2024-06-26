#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    int n; cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    int ans = 0;
    multiset<int> towers;
    for (int i = 0; i < n; ++i){
        auto it = towers.upper_bound(arr[i]);
        if (it == towers.end()) towers.insert(arr[i]);
        else {
            towers.erase(it);
            towers.insert(arr[i]);
        }
    }
    cout << towers.size() << endl;
}

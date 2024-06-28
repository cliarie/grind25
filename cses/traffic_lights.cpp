#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <utility>
using namespace std;

int main(){
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int x, n;
    cin >> x >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    multiset<int> lengths;
    set<pair<int, int>> ranges;
    lengths.insert(x);
    ranges.insert(make_pair(1, x));
    for (int i = 0; i < n; ++i){
        auto range = lower_bound(ranges.begin(), ranges.end(), make_pair(arr[i], arr[i]));
        cout << "light " << arr[i] << endl;
        cout << range->first << " " << range->second << endl;
        lengths.erase(range->second - range->first + 1);
        lengths.insert(range->second - arr[i] + 1);
        lengths.insert(arr[i] = range->first + 1);
        ranges.insert(make_pair(range->first, arr[i]));
        ranges.insert(make_pair(arr[i] + 1, range->second));
    }
    for (auto l : lengths) cout << l << endl;
}

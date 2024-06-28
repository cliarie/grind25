#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <utility>
#define ll long long
using namespace std;

int main(){
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    int x, n;
    cin >> x >> n;
    vector<ll> arr(n, 0);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    multiset<ll> lengths;
    set<pair<ll, ll>> ranges;
    lengths.insert(x);
    ranges.insert({1, x});
    for (int i = 0; i < n; ++i){
        auto range = ranges.upper_bound({arr[i], x});
        //for (auto i : ranges) cout  << i.first << " " << i.second << endl;
        range--;
        lengths.erase(lengths.find(range->second - range->first + 1));
        lengths.insert(range->second - arr[i]);
        lengths.insert(arr[i] - range->first + 1);
        ranges.insert({range->first, arr[i]});
        ranges.insert({arr[i] + 1, range->second});

        ranges.erase(range);
 //for (auto i : ranges) cout  << i.first << " dd " << i.second << endl;
 //for (auto i : lengths) cout  << "ll" << i << endl;
        cout << *lengths.rbegin() << " ";
    }
}

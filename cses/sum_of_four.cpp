#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
two sum but with sum of all pairs -> O(N^2 log n)
*/
int main(){
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    int n, x; cin >> n >> x;
    multimap<int, pair<int, int>> pairsum; // map that maps sums to positions of the two
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; ++i) {cin >> arr[i];}

    for (int i = 1; i <= n; ++i){
        for (int j = i + 1; j <= n; ++j){
            pairsum.insert({arr[i] + arr[j], {i, j}});
        }
    }

    for (auto it = pairsum.begin(); it != pairsum.end(); ++it){
        //find_if runs linearly
        //auto match = find_if(pairsum.begin(), pairsum.end(), [&](const auto& other){return (other.first == (x - it->first) && other.second.first != (it->second.first) && other.second.first != (it->second.second) && other.second.second != (it->second.first ) && other.second.second != (it->second.second));});
        auto match = pairsum.find(x-it->first);
        if (match != pairsum.end() && match->second.first != (it->second.first) && match->second.first != (it->second.second) && match->second.second != (it->second.first ) && match->second.second != (it->second.second)){
            cout << match->second.first << " " << match->second.second << " " << it->second.first << " " << it->second.second << endl;
            return 0;
        }
    }

    cout << "IMPOSSIBLE" << endl;
}

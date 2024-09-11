#include <iostream>
#include <vector>
#include <map>
#include <utility>
#define ll long long
using namespace std;

int main(){
    #ifdef LOCAL_TESTING
       freopen("../input.txt", "r", stdin);
       freopen("../output.txt", "w", stdout);
    #endif

    ll n;
    cin >> n;

    map<ll, pair<int, int>> mp;
    vector<ll> arr(n);

    for (int i = 0; i < n; i++){
        cin >> arr[i];
        if (i == 0) mp[arr[i]] = {0, 0};
        else{
            auto it = mp.upper_bound(arr[i]);
            if (it != mp.begin()) {
                if (!prev(it)->second.second) {
                    cout << prev(it)->first << " ";
                    prev(it)->second.second = 1;
                } else {
                    cout << it->first << " ";
                    it->second.first = 1;
                }
            } else {
                cout << (mp.begin())->first << " ";
                mp.begin()->second.first = 1;
            }
            mp[arr[i]] = {0, 0};
        }
    }
    cout << endl;

}

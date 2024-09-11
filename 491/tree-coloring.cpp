#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

bool check(int x, vector<int> sizes){
    // cout << "Checking " << x << endl;
    int remaining = 0;
    int n = sizes.size();
    for (int i = 1; i <= n; ++i){
        // cout << "initial " << sizes[i - 1] << endl;
        sizes[i - 1]--;
        sizes[i - 1] -= (x - i);
        // cout << i << " " << sizes[i - 1] << endl;
        if (sizes[i - 1] > 0) remaining += sizes[i - 1];
    }
    x -= n;
    // cout << "remain " << x << " " << remaining << endl;
    return remaining <= x;
}

int main(){
    #ifdef LOCAL_TESTING
       freopen("../input.txt", "r", stdin);
       freopen("../output.txt", "w", stdout);
    #endif

    int t; cin >> t;
    for (int i = 0; i < t; ++i){
        int n; cin >> n;
        unordered_map<int, vector<int>> groups;
        groups[0].push_back(1);
        for (int j = 2; j <= n; ++j){
            int e; cin >> e;
            groups[e].push_back(j);
        }

        vector<int> sizes;
        for (auto &p : groups){
            sizes.push_back(p.second.size());
        }

        sort(sizes.begin(), sizes.end(), greater<int>());

        int l = groups.size();
        int r = n;

        while (l < r){
            int mid = (l + r) / 2;
            if (check(mid, sizes)){
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        cout << l << endl;

        // int man = groups.size();
        // int rest = n - man - (man - 1);
        // rest = (rest + 1) / 2;
        // rest = max(0, rest);
        // cout << man + rest << endl;
    }
}

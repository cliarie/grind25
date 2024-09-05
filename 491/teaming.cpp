#include <iostream>
#include <vector>
using namespace std;

int main(){
    #ifdef LOCAL_TESTING
       freopen("../input.txt", "r", stdin);
       freopen("../output.txt", "w", stdout);
    #endif
    // choose two days, day counts >= n/2
    int t; cin >> t;
    for (int i = 0; i < t; ++i){
        int n; cin >> n;
        vector<vector<int> > days(5);
        for (int j = 0; j < n; ++j){
            for (int k = 0; k < 5; ++k) {
                int x; cin >> x;
                if (x) days[k].push_back(j);
            }
        }
        bool found = false;
        for (int j = 0; j < 5; ++j){
            if (found) break;
            if (days[j].size() < n / 2) continue;
            vector<int> seen(n);
            for (auto &p : days[j]) seen[p]++;
            for (int k = j + 1; k < 5; ++k){
                if (found) break;
                if (days[k].size() < n / 2) continue;
                for (auto &np : days[k]) seen[np]++;
                for (int id = 0; id < n; ++id) {
                    if (!seen[id]) break;
                    if (id == n - 1) found = true;
                }
                for (auto &np : days[k]) seen[np]--;
            }
        }
        if (found) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

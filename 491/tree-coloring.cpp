#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

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

        int man = groups.size();
        int rest = n - man - (man - 1);
        rest = (rest + 1) / 2;
        rest = max(0, rest);
        cout << man + rest << endl;
    }
}

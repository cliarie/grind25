#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    #ifdef LOCAL_TESTING
       freopen("../input.txt", "r", stdin);
       freopen("../output.txt", "w", stdout);
    #endif
    int n; cin >> n;
    vector<int> pslices(n);
    vector<int> prefix(n);
    for (int i = 0; i < n; ++i){
        cin >> pslices[i];
    }
    prefix[0] = pslices[0];
    for (int i = 1; i < n; ++i){
        prefix[i] = prefix[i - 1] + pslices[i];
    }

    int m; cin >> m;
    for (int i = 0; i < m; ++i){
        int q; cin >> q;
        auto it = lower_bound(prefix.begin(), prefix.end(), q);
        int idx;
        if (it == prefix.end()) idx = 1;
        else idx = it - prefix.begin() + 1;
        cout << idx << endl;
    }

}

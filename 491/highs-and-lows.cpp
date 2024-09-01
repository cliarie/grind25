// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    #ifdef LOCAL_TESTING
       freopen("../input.txt", "r", stdin);
       freopen("../output.txt", "w", stdout);
    #endif
    int t; cin >> t;
    for (int i = 0; i < t; ++i){
        int n; cin >> n;
        vector<int> a(n);
        for (int j = 0; j < n; ++j){
            cin >> a[j];
        }
        sort(a.begin(), a.end());
        int mn1 = a[0], mn2 = a[1];
        int mx1 = a[n - 1], mx2 = a[n - 2];
        cout << (mx2 - mn2) + (mx1 - mn1) << endl;
    }
}

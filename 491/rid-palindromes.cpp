// greedy search
// keep change array: if prev two are changed, don't change, check palindromes
// a b b a c

#include <iostream>
#include <vector>
using namespace std;

int main(){
    #ifdef LOCAL_TESTING
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--){
        string s; cin >> s;
        int total = 0;
        vector<int> change(s.length(), 0);
        if (s[0] == s[1]) {
            change[1] = 1;
            total++;
        }
        for (int i = 2; i < s.length(); ++i){
            if (s[i] == s[i - 1] && !change[i - 1]) {
                change[i] = 1;
                // cout << i << endl;
                total++;
            }
            else if (s[i] == s[i - 2] && !change[i - 2]) {
                change[i] = 1;
                // cout << i << endl;
                total++;
            }
        }
        // cout << endl;
        cout << total << endl;
    }
}

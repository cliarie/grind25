#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int find(ll v, vector<ll> &dsu){
    if (v != dsu[v]){
        dsu[v] = find(dsu[v], dsu);
    }
    return dsu[v];
}

int main(){
    #ifdef LOCAL_TESTING
       freopen("../input.txt", "r", stdin);
       freopen("../output.txt", "w", stdout);
    #endif

    int n; cin >> n;
    ll max_len = 0;
    vector<pair<string, vector<ll>>> substrings(n);
    for (ll i = 0; i < n; ++i){
        string s; cin >> s;
        ll k; cin >> k;

        vector<ll> indexes(k);
        for (ll j = 0; j < k; ++j){
            cin >> indexes[j]; indexes[j]--;
            max_len = max(max_len, indexes[j] + (ll)s.size());
        }
        substrings[i] = {s, indexes};
    }

    string password(max_len, '?');
    vector<ll> dsu(max_len + 1);

    for (ll i = 0; i <= max_len; ++i){
        dsu[i] = i;
    }

    for (auto &s : substrings){
        string &str = s.first;
        vector<ll> &indexes = s.second;
        for (auto start : indexes){
            ll idx = start;
            int k = 0;
            while (k < str.length()){
                ll a = find(idx, dsu);
                k += a - idx;
                if (k >= str.length()) break;
                password[a] = str[k];
                dsu[a] = find(a + 1, dsu);
                idx = a + 1;
                k++;
            }
        }
    }

    for (auto &c : password){
        if (c == '?') c = 'a';
    }
    cout << password << endl;
}

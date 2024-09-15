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

void join(ll a, ll b, vector<ll> &dsu){
    dsu[a] = b;
}

int main(){
    #ifdef LOCAL_TESTING
       freopen("../input.txt", "r", stdin);
       freopen("../output.txt", "w", stdout);
    #endif

    int n; cin >> n;
    vector<int> dsu(n + 1);

    for(int i = 1; i <= n; i++){
        dsu[i] = i;
    }

    for (int i = 0; i < n; ++i){
        string s; cin >> s;
        int k; cin >> k;
        for (int j = 0; j < k; ++j){
            int x; cin >> x;
            join(x, i + 1, dsu);
        }
    }
}

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
    vector<ll> dsu(n + 1), arr(n), water(n, 0);

    for (int i = 0; i <= n; ++i) dsu[i] = i;
    for (int i = 0; i < n; ++i) cin >> arr[i];

    int q; cin >> q;
    for (int i = 0; i < q; ++i){
        int type; cin >> type;
        if (type == 1){
            ll num, amt; cin >> num >> amt; num--;

            ll numr = find(num, dsu);
            while(numr < n && amt > 0){
                ll capacity_left = arr[numr] - water[numr];
                if (amt <= capacity_left){
                    water[numr] += amt;
                    amt = 0;
                }
                else{
                    water[numr] = arr[numr];
                    amt -= capacity_left;
                    join(numr, numr + 1, dsu); // merge with next reservoir
                }
                numr = find(numr, dsu); // find next available reservoir
            }
        }
        else{
            ll num; cin >> num; num--;
            cout << water[num] << endl;
        }
    }
}

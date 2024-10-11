#include <iostream>
#define MAXN 100005
#define ll long long

using namespace std;

ll n, m;
ll a[MAXN], ft[MAXN];

// find lowest bit
ll lbt(ll x){
    return x & (-x);
}

void add(ll idx, ll delta){
    while (idx <= n){
        ft[idx] += delta;
        idx += lbt(idx);
    }
}

ll query(ll idx){
    ll sum = 0;
    while (idx > 0){
        sum += ft[idx];
        idx -= lbt(idx);
    }
    return sum;
}

int main(){
    #ifdef LOCAL_TESTING
       freopen("../input.txt", "r", stdin);
       freopen("../output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    a[0] = 0;
    for (ll i = 1; i <= n; ++i){
        a[i] = 0;
    }

    ll t, x, y;
    for (ll i = 1; i <= n; ++i){
        cin >> t >> x >> y;
        if (t == 1){
            add(x, y);
        } else { // find range sum
            ll r_sum = query(y) - query(x - 1);
            cout << r_sum << endl;
        }
    }
}

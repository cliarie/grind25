#include <iostream>
#include <vector>
#define ll long long
using namespace std;

const int MOD = 1e9 + 7;

unsigned ll k1, k2;

unsigned ll xorShift128Plus(){
    unsigned ll k3 = k1, k4 = k2;
    k1 = k4;
    k3 ^= k3 << 23;
    k2 = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);
    return k2 + k4;
}

int n, m, u[100001], v[100001];
unsigned ll w[100001];

void gen(){
    cin >> n >> m >> k1 >> k2;
    for (int i = 1; i <= m; ++i){
        u[i] = xorShift128Plus() % n + 1;
        v[i] = xorShift128Plus() % n + 1;
        w[i] = xorShift128Plus();
    }
}

struct Edge{
    int u, v;
    unsigned ll w;
    bool operator < (const Edge &oth) const{
        return w < oth.w;
    }
};

struct DSU{
    vector<int> par, sz;
    DSU(int n){
        par.resize(n + 1);
        sz.resize(n + 1);
        for (int i = 1; i <= n; ++i){
            par[i] = i;
            sz[i] = 1;
        }
    }
    int find(int u){
        return par[u] == u ? u : par[u] = find(par[u]);
    }
    void join(int u, int v){
        u = find(u);
        v = find(v);
        if (u == v) return;
        if (sz[u] < sz[v]) swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
    }
};

int main(){
    #ifdef LOCAL_TESTING
       freopen("../input.txt", "r", stdin);
       freopen("../output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false); // untie cin from cout
    std::cin.tie(nullptr); // Break the tie between cin and cout
    int t; cin >> t;
    while (t--){
        gen();
        vector<Edge> edges;
        for (int i = 1; i <= m; ++i){
            edges.push_back({u[i], v[i], w[i]});
        }
        sort(edges.begin(), edges.end());

        DSU dsu(n);
        ll total = 0;
        int edges_used = 0;

        for (auto edge : edges){
            if (dsu.find(edge.u) != dsu.find(edge.v)){
                dsu.join(edge.u, edge.v);
                total = (total + (edge.w) % MOD) % MOD;
                edges_used++;
                if (edges_used == n - 1) break;
            }
        }
        if (n == 1) cout << 0 << endl;
        else if (edges_used != n - 1) cout << 0 << endl;
        else cout << total % MOD << endl;

    }
}

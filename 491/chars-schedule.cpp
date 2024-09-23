// #include <iostream>
// #include <vector>
// using namespace std;

// const int MAXN = 2 * 1e5 + 1;
// const int MAXLOG = 20; // log2(MAXN)

// int n, m;
// vector<int> adj[MAXN];
// int depth[MAXN];
// int tin[MAXN], tout[MAXN], timer;
// int up[MAXN][MAXLOG];  //binary lifting table

// void dfs(int u, int p){
//     timer++;
//     tin[u] = timer;
//     up[u][0] = p;
//     depth[u] = depth[p] + 1;
//     for (int i = 1; i < MAXLOG; ++i){
//         up[u][i] = up[up[u][i - 1]][i - 1];
//     }
//     for (int v : adj[u]){
//         if (v != p){
//             depth[v] = depth[u] + 1;
//             dfs(v, u);
//         }
//     }
//     timer++;
//     tout[u] = timer;
// }

// bool is_ancestor(int u, int v) {
//     // true if u is ancestor of v
//     return tin[u] <= tin[v] && tout[u] >= tout[v];
// }

// int lca(int u, int v){
//     if (is_ancestor(u, v)) return u;
//     if (is_ancestor(v, u)) return v;

//     for (int i = MAXLOG - 1; i >= 0; --i){
//         if (up[u][i] != 0 && !is_ancestor(up[u][i], v))
//             u = up[u][i];
//     }
//     return up[u][0];
// }

// int main(){
//     #ifdef LOCAL_TESTING
//        freopen("../input.txt", "r", stdin);
//        freopen("../output.txt", "w", stdout);
//     #endif
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int n, m; cin >> n >> m;

//     for (int i = 0; i < n - 1; ++i){
//         int u, v; cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }

//     // init depth, tin, tout, up arrays from node 1
//     depth[0] = -1;
//     dfs(1, 0);

//     timer = 2 * n; // avoid overlap with existing tin tout
//     for (int i = 0; i < m; ++i){
//         int t, a, b; cin >> t >> a >> b;
//         if (t == 1){
//             // add b connected to a
//             depth[b] = depth[a] + 1;
//             timer++;
//             tin[b] = timer;
//             up[b][0] = a;
//             for (int k = 1; k < MAXLOG; ++k){
//                 up[b][k] = up[up[b][k - 1]][k - 1];
//             }
//             timer++;
//             tout[b] = timer;
//         }
//         else{
//             // query distance between a, b
//             int l = lca(a, b);
//             int dist = depth[a] + depth[b] - 2*depth[l];
//             cout << dist << endl;
//         }
//     }

// }

#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 300005;  // Adjusted size to accommodate n + m nodes
const int MAXLOG = 20;    // Sufficient for log2(MAXN)

vector<int> adj[MAXN];
int depth[MAXN];
int tin[MAXN], tout[MAXN], timer;
int up[MAXN][MAXLOG];  // Binary lifting table

void dfs(int u, int p){
    up[u][0] = p;
    depth[u] = depth[p] + 1;
    for (int i = 1; i < MAXLOG; ++i){
        up[u][i] = up[up[u][i - 1]][i - 1];
    }
    for (int v : adj[u]){
        if (v != p){
            dfs(v, u);
        }
    }
}

int lca(int u, int v){
    if (depth[u] < depth[v]) swap(u, v);

    // Lift u up so that depth[u] == depth[v]
    for (int i = MAXLOG - 1; i >= 0; --i){
        if (depth[u] - (1 << i) >= depth[v]){
            u = up[u][i];
        }
    }
    if (u == v) return u;

    // Lift u and v up together
    for (int i = MAXLOG -1; i >= 0; --i){
        if (up[u][i] != 0 && up[u][i] != up[v][i]){
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

int main(){
    #ifdef LOCAL_TESTING
       freopen("../input.txt", "r", stdin);
       freopen("../output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Initialize up[0][i]
    for (int i = 0; i < MAXLOG; ++i)
        up[0][i] = 0;

    int n, m; cin >> n >> m;

    for (int i = 0; i < n - 1; ++i){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    depth[0] = -1; // Set depth of dummy node 0
    dfs(1, 0);

    timer = 2 * n; // Avoid overlap with existing tin, tout
    for (int i = 0; i < m; ++i){
        int t, a, b; cin >> t >> a >> b;
        if (t == 1){
            // Add new node b connected to a
            adj[a].push_back(b);
            adj[b].push_back(a);

            depth[b] = depth[a] + 1;
            up[b][0] = a;
            for (int k = 1; k < MAXLOG; ++k){
                up[b][k] = up[up[b][k - 1]][k - 1];
            }
        }
        else{
            // Query distance between nodes a and b
            int l = lca(a, b);
            int dist = depth[a] + depth[b] - 2 * depth[l];
            cout << dist << '\n';
        }
    }

    return 0;
}

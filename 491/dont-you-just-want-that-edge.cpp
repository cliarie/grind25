#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 200005;  // Maximum number of nodes
const int LOGN = 20;      // log2(MAXN) is approximately 17.6

struct Edge {
    int u, v;       // Endpoints of the edge
    int w;          // Weight of the edge
    int idx;        // Original index of the edge
    bool in_mst;    // Flag to indicate if the edge is in the MST
};

int n, m;
vector<Edge> edges;
vector<pair<int, int>> adj[MAXN];  // Adjacency list for the MST
int depth[MAXN];
int parent[MAXN][LOGN];
int max_weight[MAXN][LOGN];
long long total_mst_weight = 0;

// Disjoint Set Union (Union-Find) data structure
struct DSU {
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; ++i)
            parent[i] = i;
    }
    int find(int v) {
        if (v != parent[v])
            parent[v] = find(parent[v]);
        return parent[v];
    }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b)
            return false;
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
        return true;
    }
};

// DFS to build depth, parent, and max_weight tables for binary lifting
void dfs(int u, int p) {
    parent[u][0] = p;
    for (int k = 1; k < LOGN; ++k) {
        parent[u][k] = parent[parent[u][k - 1]][k - 1];
        max_weight[u][k] = max(max_weight[u][k - 1], max_weight[parent[u][k - 1]][k - 1]);
    }
    for (auto [v, w] : adj[u]) {
        if (v != p) {
            depth[v] = depth[u] + 1;
            max_weight[v][0] = w;
            dfs(v, u);
        }
    }
}

// Function to find the maximum edge weight between nodes u and v in the MST
int get_max_weight(int u, int v) {
    if (depth[u] < depth[v])
        swap(u, v);
    int max_w = 0;

    // Bring u up to the depth of v
    for (int k = LOGN - 1; k >= 0; --k) {
        if (depth[u] - (1 << k) >= depth[v]) {
            max_w = max(max_w, max_weight[u][k]);
            u = parent[u][k];
        }
    }

    if (u == v)
        return max_w;

    // Bring u and v up together until their parents are the same
    for (int k = LOGN - 1; k >= 0; --k) {
        if (parent[u][k] != parent[v][k]) {
            max_w = max({max_w, max_weight[u][k], max_weight[v][k]});
            u = parent[u][k];
            v = parent[v][k];
        }
    }

    // Include the edge just before the LCA
    max_w = max({max_w, max_weight[u][0], max_weight[v][0]});
    return max_w;
}

int main() {
    #ifdef LOCAL_TESTING
       freopen("../input.txt", "r", stdin);
       freopen("../output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    edges.resize(m);

    for (int i = 0; i < m; ++i) {
        Edge& e = edges[i];
        cin >> e.u >> e.v >> e.w;
        e.idx = i;
        e.in_mst = false;
    }

    // Kruskal's algorithm to build the MST
    DSU dsu(n);
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.w < b.w;
    });

    for (Edge& e : edges) {
        if (dsu.unite(e.u, e.v)) {
            e.in_mst = true;
            total_mst_weight += e.w;
            adj[e.u].emplace_back(e.v, e.w);
            adj[e.v].emplace_back(e.u, e.w);
        }
    }

    // Prepare for binary lifting
    depth[1] = 0;
    dfs(1, 0);

    vector<long long> answer(m);
    for (const Edge& e : edges) {
        if (e.in_mst) {
            // Edge is in MST, total weight remains the same
            answer[e.idx] = total_mst_weight;
        } else {
            // Edge is not in MST, compute new total weight
            int max_w = get_max_weight(e.u, e.v);
            long long new_total = total_mst_weight - max_w + e.w;
            answer[e.idx] = new_total;
        }
    }

    // Output the results
    for (int i = 0; i < m; ++i) {
        cout << answer[i] << '\n';
    }

    return 0;
}

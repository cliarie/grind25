#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

// Function to perform iterative DFS and fill the order vector
void dfs1(int u, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &order) {
    stack<pair<int, bool>> s;
    s.emplace(u, false);

    while (!s.empty()) {
        auto [node, processed] = s.top();
        s.pop();

        if (node < 0) { // Post-processing
            order.push_back(~node);
            continue;
        }

        if (visited[node])
            continue;

        visited[node] = true;
        s.emplace(~node, true); // Mark for post-processing

        for (auto &v : adj[node]) {
            if (!visited[v])
                s.emplace(v, false);
        }
    }
}

// Function to perform iterative DFS on the transposed graph and assign components
void dfs2(int u, int label, vector<vector<int>> &adj_rev, vector<int> &component, vector<bool> &visited) {
    stack<int> s;
    s.push(u);
    visited[u] = true;
    component[u] = label;

    while (!s.empty()) {
        int node = s.top();
        s.pop();

        for (auto &v : adj_rev[node]) {
            if (!visited[v]) {
                visited[v] = true;
                component[v] = label;
                s.push(v);
            }
        }
    }
}

int main(){
    #ifdef LOCAL_TESTING
       freopen("../input.txt", "r", stdin);
       freopen("../output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<ll> costs(n);
    for(auto &x : costs) cin >> x;

    int m;
    cin >> m;

    vector<vector<int>> adj(n, vector<int>());
    for(int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1); // 0-based indexing
    }

    // First pass of Kosaraju's algorithm to get the order
    vector<bool> visited(n, false);
    vector<int> order;

    for(int u=0; u<n; u++){
        if(!visited[u]){
            dfs1(u, adj, visited, order);
        }
    }

    // Transpose the graph
    vector<vector<int>> adj_rev(n, vector<int>());
    for(int u=0; u<n; u++){
        for(auto &v : adj[u]){
            adj_rev[v].push_back(u);
        }
    }

    // Second pass to assign components
    vector<int> component(n, -1);
    int label = 0;
    fill(visited.begin(), visited.end(), false);

    for(int i = order.size()-1; i >=0; i--){
        int u = order[i];
        if(!visited[u]){
            dfs2(u, label, adj_rev, component, visited);
            label++;
        }
    }

    // Now, for each component, find min cost and count
    // Initialize min_cost to a large value and count to 0
    vector<ll> min_cost(label, LLONG_MAX);
    vector<ll> count(label, 0);

    for(int u=0; u<n; u++){
        int comp = component[u];
        if(costs[u] < min_cost[comp]){
            min_cost[comp] = costs[u];
            count[comp] = 1;
        }
        else if(costs[u] == min_cost[comp]){
            count[comp]++;
        }
    }

    // Calculate total cost and number of ways
    ll total_cost = 0;
    ll total_ways = 1;

    for(int i=0; i<label; i++){
        total_cost += min_cost[i];
        total_ways = (total_ways * count[i]) % MOD;
    }

    cout << total_cost << " " << total_ways;
}

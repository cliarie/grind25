#include <vector>
#include <iostream>
#include <utility>
#include <functional>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Edge {
    int u;
    int v;
    int index;
};

int main(){
    #ifdef LOCAL_TESTING
       freopen("../input.txt", "r", stdin);
       freopen("../output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false); // untie cin from cout
    std::cin.tie(nullptr); // Break the tie between cin and cout
    int T;
    cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;

        // Initialize Union-Find parent array
        vector<int> parent(n+1);
        for(int i=1;i<=n;i++) parent[i] = i;

        // Function to find the root of a set with path compression
        auto find_set = [&](auto &find_set_ref, int x) -> int{
            if(parent[x] != x){
                parent[x] = find_set_ref(find_set_ref, parent[x]);
            }
            return parent[x];
        };

        // Read all edges
        vector<Edge> edges(m);
        for(int i=0;i<m;i++){
            cin >> edges[i].u >> edges[i].v;
            edges[i].index = i+1; // 1-based indexing
        }

        // Build adjacency list for DFS later
        vector<vector<pair<int, int>>> adj(n+1, vector<pair<int, int>>());

        bool found = false;
        int cycle_edge_idx = -1;
        int cycle_u = -1, cycle_v = -1;

        // Process edges using Union-Find
        for(int i=0;i<m;i++){
            int u = edges[i].u;
            int v = edges[i].v;
            int idx = edges[i].index;

            int set_u = find_set(find_set, u);
            int set_v = find_set(find_set, v);

            if(set_u != set_v){
                parent[set_u] = set_v;
                adj[u].emplace_back(v, idx);
                adj[v].emplace_back(u, idx);
            }
            else{
                // Cycle detected by adding edge (u, v)
                found = true;
                cycle_edge_idx = idx;
                cycle_u = u;
                cycle_v = v;
                // Add the current edge to adjacency list for DFS
                adj[u].emplace_back(v, idx);
                adj[v].emplace_back(u, idx);
                break; // Stop processing further edges
            }
        }

        if(!found){
            cout << "-1\n";
            continue;
        }

        // Now, perform DFS to find the cycle
        // We have an edge (cycle_u, cycle_v) that forms the cycle
        // We need to find a path from cycle_u to cycle_v excluding the current edge

        // To avoid revisiting the current edge, we'll keep track of it
        // We'll use the edge index to identify it
        int excluded_edge = cycle_edge_idx;

        // Variables to store the path
        vector<int> path_edges;
        bool cycle_found = false;

        // DFS function
        // Returns true if path is found
        function<bool(int, int, vector<int>&, vector<bool>&)> dfs = [&](int current, int target, vector<int> &current_path, vector<bool> &visited) -> bool{
            if(current == target){
                cycle_found = true;
                return true;
            }
            visited[current] = true;
            for(auto &[neighbor, edge_idx] : adj[current]){
                if(edge_idx == excluded_edge) continue; // Skip the edge that forms the cycle
                if(!visited[neighbor]){
                    current_path.push_back(edge_idx);
                    if(dfs(neighbor, target, current_path, visited)){
                        return true;
                    }
                    current_path.pop_back();
                }
            }
            return false;
        };

        vector<int> current_path;
        vector<bool> visited(n+1, false);
        dfs(cycle_u, cycle_v, current_path, visited);

        if(!cycle_found){
            cout << "-1\n";
            continue;
        }

        vector<int> cycle_edges = current_path;
        cycle_edges.push_back(cycle_edge_idx); // Include the edge that forms the cycle

        sort(cycle_edges.begin(), cycle_edges.end());

        for(int i=0;i<cycle_edges.size();i++){
            if(i > 0) cout << ' ';
            cout << cycle_edges[i];
        }
        cout << '\n';
    }
}

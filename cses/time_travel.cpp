#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#define pair pair<int, int>
#define ll long long
const ll inf = 1e9 + 1;
using namespace std;

int search(map<int, vector<int>> &moment, int curmom, int srcdist, int size){
    auto it = upper_bound(moment[curmom].begin(), moment[curmom].end(), srcdist);
    if (it == moment[curmom].end()) return -1;
    return *it;
    // int l = srcdist, r = size;
    // while (r > l){
    //     int mid = (l + r) / 2;
    //     if (moment[mid] == curmom) return mid;

    // }
}

int main(){
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    int n, t; cin >> n >> t;
    vector<vector<pair>> adj(n + 1); // pair stores moment of edge connection
    for (int i = 1; i <= t; ++i){
        int m; cin >> m;
        for (int j = 0; j < m; ++j){
            int a, b; cin >> a >> b;
            adj[a].push_back({b, i});
            adj[b].push_back({a, i});
        }
    }
    int k; cin >> k;
    map<int, vector<int>> moment;
    for (int i = 1; i <= k; ++i) {
        int m; cin >> m;
        moment[m].push_back(i);
    }
    // end of reading input


    // classic dijkstras
    vector<int> dist (n + 1, inf); // min moves to reach i
    int start = 1;
    dist[start] = 0; // zero moves to reach 1
    priority_queue<pair, vector<pair>, greater<pair>> q; // dist, node
    q.push({0, 1});
    while(!q.empty()){
        //cout << "?";
        auto temp = q.top();
        int cdist = temp.first, node = temp.second;
        q.pop();
        //cout << cdist << node <<endl;
        if (node == n){
            cout << dist[node] << endl;
            return 0;
        }
        if (cdist != dist[node]) continue; // only go through neighbors of a node once
        for (auto &i : adj[node]){
            // let edge {v, u} belong to moment 2, then find min index in moment where moment[i] = 2;
            // also, i must be greater than dist[v] (source)
            // then dist[u] (target) = min(dist[u], i);
            // find such i hm
            int index = search(moment, i.second, dist[node], k);
            //cout << "i:" << index << " " << i.first << " " << i.second << endl;
            if (index != -1 && index < dist[i.first]){
                q.push({dist[i.first] = index, i.first});
            }
        }
    }
    cout << -1 << endl;
}

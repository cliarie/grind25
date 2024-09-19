#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void dfs(int u, vector<vector<int>>& graph, vector<int>& colors, int k){
    for (int v : graph[u]){
        if (colors[v] != -1) continue;
        for (int c = 0; c < k; ++c){
            bool found = false;
            for (int w : graph[v]){
                if (colors[w] == c){
                    found = true;
                    break;
                }
            }
            if (!found){
                colors[v] = c;
                break;
            }
        }
        if (colors[v] == -1){
            cout << -1 << endl;
            exit(0);
        }
        dfs(v, graph, colors, k);
    }
}

int main(){
    #ifdef LOCAL_TESTING
       freopen("../input.txt", "r", stdin);
       freopen("../output.txt", "w", stdout);
    #endif
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> graph(n);
    vector<int> colors(n, -1);
    for (int i = 0; i < m; ++i){
        int u, v; cin >> u >> v; u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 0; i < n; ++i){
        if (colors[i] != -1) continue;
        colors[i] = 0;
        dfs(i, graph, colors, k);
    }

    // for (int i = 0; i < n; ++i){
    //     if (colors[i] != -1) continue;
    //     colors[i] = 0;
    //     queue<int> q; q.push(i);
    //     while (!q.empty()){
    //         int u = q.front(); q.pop();
    //         for (int v : graph[u]){
    //             if (colors[v] != -1) continue;
    //             // color with max k colors
    //             for (int c = 0; c < k; ++c){
    //                 bool found = false;
    //                 for (int w : graph[v]){
    //                     if (colors[w] == c){
    //                         found = true;
    //                         break;
    //                     }
    //                 }
    //                 if (!found){
    //                     colors[v] = c;
    //                     break;
    //                 }
    //             }
    //             if (colors[v] == -1){
    //                 cout << -1 << endl;
    //                 return 0;
    //             }
    //             q.push(v);
    //         }
    //         }
    //     }
    // }


    for (int i = 0; i < n; ++i){
        cout << colors[i] + 1 << endl;
    }
}

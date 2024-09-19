#include <iostream>
#include <vector>
using namespace std;

int main(){
    #ifdef LOCAL_TESTING
       freopen("../input.txt", "r", stdin);
       freopen("../output.txt", "w", stdout);
    #endif

    int n, m; cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; ++i){
        int a, b; cin >> a >> b; --a; --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // bus: n - 2 nodes have 2 edges, 2 nodes have 1 edge
    // ring: n nodes have 2 edges
    // star: n - 1 nodes have 1 edge, 1 node has n - 1 edges

    vector<int> types(3); // 0: 1 edges, 1: 2 edges, 2: n - 1 edges
    for (auto v : graph){
        if (v.size() == 1) types[0]++;
        else if (v.size() == 2) types[1]++;
        else if (v.size() == n - 1) types[2]++;
        else {
            cout << "unknown topology" << endl;
            return 0;
        }
    }
    if (types[0] == 2 && types[1] == n - 2) cout << "bus topology" << endl;
    else if (types[1] == n) cout << "ring topology" << endl;
    else if (types[0] == n - 1 && types[2] == 1) cout << "star topology" << endl;
    else cout << "unknown topology" << endl;
}

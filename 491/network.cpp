#include <iostream>
#include <vector>
using namespace std;

class DSU{
public:
    vector<int> parent, size;
    DSU(int n){
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; ++i){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int find(int v){
        if (v != parent[v]){
            parent[v] = find(parent[v]);
        }
        return parent[v];
    }

    void join(int a, int b){
        int repa = find(a);
        int repb = find(b);

        if (repa == repb) return;

        if (size[repa] < size[repb]){
            swap(repa, repb);
        }
        size[repa] += size[repb];
        parent[repb] = repa;
    }
};

int main(){
    #ifdef LOCAL_TESTING
       freopen("../input.txt", "r", stdin);
       freopen("../output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    for (int i = 0; i < m; ++i){
        int count; cin >> count;
        vector<int> users(count);
        for (int j = 0; j < count; ++j){
            cin >> users[j]; users[j]--;
        }

        for (int j = 1; j < count; ++j){
            dsu.join(users[j], users[j-1]);
        }
    }

    for (int i = 0; i < n; ++i){
        cout << dsu.size[dsu.find(i)] << " ";
    }
    cout << endl;
}

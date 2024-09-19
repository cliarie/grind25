#include <iostream>
#include <vector>

using namespace std;

int main(){
    #ifdef LOCAL_TESTING
       freopen("../input.txt", "r", stdin);
       freopen("../output.txt", "w", stdout);
    #endif

    int n, s; cin >> n >> s; --s;
    vector<vector<int>> graph(n);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i){
        cin >> b[i];
    }
    if (!a[0]) {
        cout << "NO" << endl; return 0;
    }
    if (a[s]){
        cout << "YES" << endl; return 0;
    }
    if (b[s]){
        for (int i = s; i < n; ++i){
            if (a[i] && b[i]){
                cout << "YES" << endl; return 0;
            }
        }
    }
    cout << "NO" << endl; return 0;
}

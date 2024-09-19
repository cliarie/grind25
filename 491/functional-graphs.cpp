#include <iostream>
#include <vector>
using namespace std;

int main(){
    #ifdef LOCAL_TESTING
       freopen("../input.txt", "r", stdin);
       freopen("../output.txt", "w", stdout);
    #endif

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i){
        cin >> a[i]; a[i]--;
    }
    for (int i = 0; i < n; ++i){
        if (a[a[a[i]]] == i && a[i] != i){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}

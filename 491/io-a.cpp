#include <iostream>
using namespace std;

int main(){
    int n; cin >> n;
    for (int i = 0; i < n; ++i){
        int ans = 0;
        int a, b; cin >> a >> b;
        for (int t = 0 ; t < a; ++t){
            int x; cin >> x;
            ans += x;
        }
        for (int t = 0; t < b; ++t){
            int x; cin >> x;
            ans -= x;
        }
        cout << ans << endl;
    }
}

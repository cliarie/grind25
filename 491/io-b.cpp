#include <iostream>
using namespace std;

int main(){
    while(true){
        int a, b;
        cin >> a >> b;
        int ans = 0;
        if (!a && !b) return 0;
        for (int t = 0; t < a; ++t) {
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

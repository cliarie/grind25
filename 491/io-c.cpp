#include <iostream>
using namespace std;

int main(){
    int a, b;
    while(cin >> a >> b){
        int ans = 0;
        for (int i = 0; i < a; ++i){
            int x; cin >> x;
            ans += x;
        }
        for (int i = 0; i < b; ++i){
            int x; cin >> x;
            ans -= x;
        }
        cout << ans << endl;
    }
}

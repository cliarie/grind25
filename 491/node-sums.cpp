#include <iostream>
#define ll long long
using namespace std;

int main(){
    #ifdef LOCAL_TESTING
       freopen("../input.txt", "r", stdin);
       freopen("../output.txt", "w", stdout);
    #endif

    ll t; cin >> t;
    for (int i = 0; i < t; ++i){
        ll n; cin >> n;
        ll ans = 0;
        while(n != 1){
            ans += n;
            n /= 2;
        }
        ans += 1;
        cout << ans << endl;
    }
}

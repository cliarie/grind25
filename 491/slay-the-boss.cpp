#include <iostream>
#include <cmath>
#define ll long long
using namespace std;


int main(){
    #ifdef LOCAL_TESTING
       freopen("../input.txt", "r", stdin);
       freopen("../output.txt", "w", stdout);
    #endif
    int n; cin >> n;
    for (int i = 0; i < n; ++i){
        ll wh, wa, bh, ba;
        cin >> wh >> wa >> bh >> ba;
        ll coins, a, h;
        cin >> coins >> a >> h;

        bool found = false;
        for (ll ca = 0; ca <= coins; ++ca){
            ll ch = coins - ca;
            ll wukongh = wh + h * ch;
            ll wukonga = wa + a * ca;
            if ((wukongh / ba + (wukongh%ba != 0)) >= (bh / wukonga + (bh%wukonga != 0))) {
                found = true; break;
            }
        }
        if (found) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

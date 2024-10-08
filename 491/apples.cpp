#include <iostream>
using namespace std;
#define ll long long

int main(){
    #ifdef LOCAL_TESTING
       freopen("../input.txt", "r", stdin);
       freopen("../output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--){
        ll n, b, x, y;
        cin >> n >> b >> x >> y;
        // a = a_{i-1} + x if (a_i + x < b) else a_i = a_{i-1} - y
        // find max sum for n until i = n
        ll total = 0;
        ll sum = 0;
        for(int i = 0; i < n; i++){
            if(x + sum <= b){
                sum += x;
            }else{
                sum -= y;
            }
            // cout << sum << endl;
            total += sum;
        }
        cout << total << endl;
    }
}

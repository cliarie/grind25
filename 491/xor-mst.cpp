#include <iostream>
using namespace std;
#define ll long long

// u XOR v is minimum when u and v differ in the least significant bit
// edges with smallest weights are those where vertices are different in the least significant bit
// choose smallest edge that doesn't form a cycle
int main(){
    #ifdef LOCAL_TESTING
       freopen("../input.txt", "r", stdin);
       freopen("../output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false); // untie cin from cout
    std::cin.tie(nullptr); // Break the tie between cin and cout

    ll n; cin >> n;
    ll ans = 0, k = 1;
    while(n > 1){
        ans += k * (n / 2);
        k <<= 1LL;
        n = (n + 1) / 2;
    }
    cout << ans << endl;

}

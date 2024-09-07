#include <iostream>
#include <unordered_map>
#define ll long long
using namespace std;

bool isPrime(ll n){
    if (n == 2 || n == 3) return true;
    if (n <= 1 || n%2 == 0 || n%3 == 0) return false;
    for (ll i = 5; i * i <= n; i += 6){
        if (n%i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

unordered_map<ll, int> primeFactorization(ll n){
    unordered_map<ll, int> ans;
    while (n%2 == 0){
        ans[2]++;
        n/=2;
    }
    for (ll i = 3; i * i <= n; i+=2){
        while(n%i == 0){
            ans[i]++;
            n/=i;
        }
    }
    if (n > 1) ans[n]++;
    return ans;
}
bool hasDivisor(ll a, ll b){
    unordered_map<ll, int> fa = primeFactorization(a);
    unordered_map<ll, int> fb = primeFactorization(b);

    for (const auto &[prime, count] : fb){
        fa[prime] += count;
    }
    for (const auto &[prime, exp] : fa){
        if (exp >= 2) return true;
    }
    return false;
}

int main(){
    #ifdef LOCAL_TESTING
       freopen("../input.txt", "r", stdin);
       freopen("../output.txt", "w", stdout);
    #endif
    ll a, b; cin >> a >> b;
    if (isPrime(a) && isPrime(b) && a != b){
        cout << "full credit" << endl;
    }
    else if (hasDivisor(a, b)){
        cout << "no credit" << endl;
    }
    else {
        cout << "partial credit" << endl;
    }
}

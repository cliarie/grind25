#include <iostream>
#include <set>
#define ll long long
using namespace std;

int main(){
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    int n, k; cin >> n >> k;
    set<int> children;
    for (int i = 1; i <= n; ++i) children.insert(i);

    ll i = 0;
    while(children.size() != 1){
        i = (i + k) % children.size();
        auto it = next(children.begin(), i);
        cout << *it << endl;
        children.erase(it);
    }
    cout << *(children.begin()) << endl;
}

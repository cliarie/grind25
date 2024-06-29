#include <cmath>
#include <iostream>
#include <set>
using namespace std;

int main(){
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    int n; cin >> n;

    set<int> children;
    for (int i = 1; i <= n; ++i) children.insert(i);
    auto it = next(children.begin());
    while(children.size() != 1){
        auto it2 = (next(it) == children.end()) ? next(children.begin()) : (next(next(it)) == children.end()) ? children.begin() : next(next(it));
        cout << *it << endl;
        children.erase(it);
        it = it2;
    }
    cout << *(children.begin()) << endl;
}

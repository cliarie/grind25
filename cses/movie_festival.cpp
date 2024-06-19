#include <iostream>
#include <set>
#include <utility>
using namespace std;

// sort by earliest end time then traverse all check if viewable
int main(){
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    int n;
    cin >> n;
    set<pair<int, int>> endstart;
    int a, b;
    for (int i = 0; i < n; ++i){
        cin >> a >> b;
        endstart.insert(make_pair(b, a));
    }

    int count = 0, time = 0;
    for (auto it = endstart.begin(); it != endstart.end(); ++it){
        if ((*it).second >= time) {
            count++;
            time = (*it).first;
        }
    }
    cout << count << endl;
}

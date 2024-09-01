#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> pii;
int main(){
#ifdef LOCAL_TESTING
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int total = 0, curidx = 0;
    int n, m; cin >> n >> m;
    vector<int> apps(n + 1);
    vector<int> lastread(n + 1);
    deque<pii> notifications(n + 1);

    for (int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        if (a == 1) {
            apps[b]++;
            total++;
            notifications.push_back({b, ++curidx});
        }
        else if (a == 2){
            total -= apps[b];
            apps[b] = 0;
            lastread[b] = curidx;
        }
        else{
            while(!notifications.empty() && notifications.front().second <= b){
                int appid = notifications.front().first;
                if (notifications.front().second > lastread[appid]){
                    total--;
                    lastread[appid] = notifications.front().second;
                    apps[appid]--;
                }
                notifications.pop_front();
            }
        }
        cout << total << endl;
    }
}

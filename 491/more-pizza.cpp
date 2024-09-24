#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <unordered_set>

using namespace std;

int main() {
    #ifdef LOCAL_TESTING
       freopen("../input.txt", "r", stdin);
       freopen("../output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<vector<int>> pizza_to_members(n + 1);
    vector<vector<int>> members_to_pizza(k + 1);
    vector<int> visited_pizza(n + 1), visited_members(k + 1);
    for (int i = 1; i <= k; ++i){
        int x, y; cin >> x >> y;
        pizza_to_members[x].push_back(i);
        pizza_to_members[y].push_back(i);
        members_to_pizza[i].push_back(x);
        members_to_pizza[i].push_back(y);
    }

    int happy = 0;
    for (int i = 1; i <= k; ++i){
        stack<int> s;
        s.push(i);
        while(!s.empty()){

            int cur = s.top();
            s.pop();

            int fav1 = members_to_pizza[cur][0], fav2 = members_to_pizza[cur][1];
            if (visited_pizza[fav1] && visited_pizza[fav2]) continue;

            happy++;

            if (!visited_pizza[fav1]){
                visited_pizza[fav1] = true;
                for (auto next : pizza_to_members[fav1]) {
                    if (!visited_members[next]){
                        s.push(next);
                        visited_members[next] = true;
                    }
                }
            }
            if (!visited_pizza[fav2]){
                visited_pizza[fav2] = true;
                for (auto next : pizza_to_members[fav2]) {
                    if (!visited_members[next]){
                        s.push(next);
                        visited_members[next] = true;
                    }
                }
            }
        }
    }
    cout << happy << endl;
    return 0;
}

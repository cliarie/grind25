#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    int n, x;
    cin >> n >> x;
    vector<int> nums(n + 1, 0);

    for (int i = 1; i <= n; ++i) cin >> nums[i];

    map<int, int> m;
    for (int i = 1; i <= n; ++i){
        auto it = m.find(nums[i]);
        if (it != m.end()){
            cout << m[nums[i]] << " " << i << endl;
            return 0;
        }
        m[x - nums[i]] = i;
    }
    cout << "IMPOSSIBLE" << endl;
}

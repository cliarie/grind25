#include <iostream>
#include <vector>
#include <utility>
#define ll long long
using namespace std;

/*
O(N^2 log n) 2sum wrapped in a loop lol
O(N^2 + nlogn) sort + two pointers
*/
int main(){
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    int n, x; cin >> n >> x;
    vector<pair<int, int>> arr(n + 1);
    for (int i = 1; i <= n; ++i) {cin >> arr[i].first; arr[i].second = i;}
    sort(arr.begin(), arr.end());

    for (int i = 1; i <= n; ++i){
        int r = n, l = i + 1;
        while(r > l){
            int sum = arr[r].first + arr[l].first + arr[i].first;
            if (sum == x){
                cout << arr[i].second << " " << arr[l].second << " " << arr[r].second;
                return 0;
            }
            else if (sum > x) r--;
            else l++;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}

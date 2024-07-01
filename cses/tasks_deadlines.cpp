#include <iostream>
#include <vector>
#include <utility>
#define ll long long
using namespace std;

int main(){
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    int n; cin >> n;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; ++i){
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(), arr.end());

    ll reward = 0, time = 0;
    for (int i = 0; i < n; ++i){
        time += arr[i].first;
        reward += arr[i].second - time;
    }
    cout << reward << endl;
}

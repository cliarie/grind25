#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main(){
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    sort(arr.begin(), arr.end());

    ll min = 1;
    for (int i = 0; i < n; ++i){
        if (arr[i] >= min + 1) break;
        else min += arr[i];
    }
    cout << min << endl;
}

#include <iostream>
#include <vector>
#define ll long long
using namespace std;

/*
add arr[i] to all subsets which give sum 1...currSum (min) to get subsets giving sum 1...currSum+a[i]
break if arr[i] > currSum + 1
*/
int main(){
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    sort(arr.begin(), arr.end());

    ll min = 0;
    for (int i = 0; i < n; ++i){
        if (arr[i] > min + 1) break;
        else min += arr[i];
    }
    cout << min + 1 << endl;
}

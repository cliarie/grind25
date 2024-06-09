#include <iostream>
#include <vector>
using namespace std;

/*
method using binary search
dp[i] = smallest ending element of increasing subsequence of length i
dp[i] = arr[j] where j is the largest index such that dp[j] < arr[i]
*/
int main()
{
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    vector<int> dp;

    for (int i = 0; i < n; ++i)
    {
        auto it = lower_bound(dp.begin(), dp.end(), arr[i]); // uses binary search to find the first element >= arr[i]
        if (it == dp.end())
            dp.push_back(arr[i]);
        else
            *it = arr[i];
    }
    cout << dp.size() << endl;
}
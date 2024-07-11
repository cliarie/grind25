#include <iostream>
#include <vector>

using namespace std;

/*
dp[i] = longest increasing subsequence up to index i
dp[i] = max(dp[j] + 1) where 0 <= j < i and arr[j] < arr[i]
*/
int main()
{
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    vector<int> dp(n, 1);

    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
}
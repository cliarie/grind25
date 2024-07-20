#include <iostream>
#include <vector>
using namespace std;

int main()
{
#ifdef LOCAL_TESTING
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (auto &a : arr)
        cin >> a;

    int farr = n - 1;
    vector<int> maxright(n);
    for (int i = n - 1; i >= 0; --i)
    {
        if (i + 1 < n && arr[i] > arr[i + 1])
            farr = i;
        maxright[i] = farr;
    }

    int farl = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (i - 1 >= 0 && arr[i - 1] < arr[i])
            farl = i;
        ans = max(ans, maxright[i] - farl + 1);
    }
    cout << ans;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> desired(n, 0);
    vector<int> apartments(m, 0);
    for (int i = 0; i < n; ++i)
        cin >> desired[i];
    for (int i = 0; i < m; ++i)
        cin >> apartments[i];
    sort(desired.begin(), desired.end());
    sort(apartments.begin(), apartments.end());

    for (int i = 0; i < n; ++i)
    {
        int d = desired[i];
        int lb = (d - k >= 0) ? d - k : 0;
        int ub = d + k;
        int idx = lower_bound(apartments.begin(), apartments.end(), lb) - apartments.begin(); // finds first apartment >= lb
        if (idx < m && apartments[idx] <= ub)
            apartments[idx] = -1; // mark apartment as used
    }
    int count = 0;
    for (int i = 0; i < m; ++i)
        if (apartments[i] == -1)
            ++count;
    // for (int i = 0; i < n; ++i)
    //     cout << desired[i] << " ";
    // for (int i = 0; i < m; ++i)
    //     cout << apartments[i] << " ";

    cout << count << endl;
}
#include <iostream>
#include <set>

using namespace std;

int main()
{
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;

    int x;
    multiset<int> tickets; // set that can contain nultiple elements with the same value
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        tickets.insert(x);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> x;
        auto it = tickets.upper_bound(x);
        if (it == tickets.begin())
            cout << -1 << endl;
        else
        {
            it--;
            cout << *it << endl;
            tickets.erase(it);
        }
    }
}
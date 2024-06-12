#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    int n, x;
    cin >> n >> x;
    deque<int> children(n);
    for (int i = 0; i < n; ++i)
        cin >> children[i];
    sort(children.begin(), children.end());

    int count = 0;
    int i = 0, j = n - 1;
    while (i <= j)
    {
        if (children[i] + children[j] <= x)
        {
            i++;
            j--;
        }
        else
            j--;
        count++;
    }

    cout << count << endl;
}
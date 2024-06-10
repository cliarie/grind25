#include <iostream>
#include <set>
using namespace std;

int main()
{
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    int n;
    cin >> n;
    set<int> s;
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        s.insert(temp);
    };
    cout << s.size();
}
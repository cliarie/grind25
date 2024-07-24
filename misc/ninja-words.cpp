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
    vector<string> arr(n, 0);
    for (auto &a : arr)
        cin >> a;
    string s;
    cin >> s;

    int l = 0, r = 0, segtotal = 0, segmax = 0, time = 0;
}

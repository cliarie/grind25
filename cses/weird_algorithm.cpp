#include <iostream>
using namespace std;

int main()
{
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    long long n;
    cin >> n;
    while (n > 1)
    {
        cout << n << " ";
        n = (n % 2 == 0) ? n / 2 : 3 * n + 1;
    }
    cout << 1;
}
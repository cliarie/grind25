#include <iostream>
#include <map>
#include <vector>
using namespace std;

int arrows(string s)
{
    int ans = 0;
    int l = 0, r = 0, u = 0, d = 0;
    unordered_map<char, int> dir = {{'^', 0}, {'>', 1}, {'v', 2}, {'<', 3}};
    for (auto c : s)
    {
        u += dir[c];
        l += (dir[c] + 1) % 4;
        d += (dir[c] + 2) % 4;
        r += (dir[c] + 3) % 4;
    }
    cout << u << l << d << r << endl;
    ans = min(u, l);
    ans = min(ans, d);
    ans = min(ans, r);
    return ans;
}

int main()
{
    string s = "<<<";
    cout << arrows(s) << endl;
}

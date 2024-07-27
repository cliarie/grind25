#include <iostream>
#include <map>
#include <utility>
#include <queue>
#include <vector>
using namespace std;

void look(vector<string> &b, char g, pair<int, int> pos)
{
    if (g == '^')
        for (int i = pos.first - 1; i >= 0; --i)
        {
            if (b[i][pos.second] != '.' && b[i][pos.second] != 'x' && b[i][pos.second] != 'A')
                break;
            b[i][pos.second] = 'x';
        }
    else if (g == 'v')
        for (int i = pos.first + 1; i < b.size(); ++i)
        {
            if (b[i][pos.second] != '.' && b[i][pos.second] != 'x' && b[i][pos.second] != 'A')
                break;
            b[i][pos.second] = 'x';
        }
    else if (g == '<')
        for (int i = pos.second - 1; i >= 0; --i)
        {
            if (b[pos.first][i] != '.' && b[pos.first][i] != 'x' && b[pos.first][i] != 'A')
                break;
            b[pos.first][i] = 'x';
        }
    else
        for (int i = pos.second + 1; i < b[0].length(); ++i)
        {
            if (b[pos.first][i] != '.' && b[pos.first][i] != 'x' && b[pos.first][i] != 'A')
                break;
            b[pos.first][i] = 'x';
        }
}

bool guard(vector<string> &b)
{
    int n = b.size(), m = b[0].length();

    pair<int, int> cur;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (b[i][j] == 'A')
                cur = {i, j};
            else if (b[i][j] != 'X' && b[i][j] != '.' && b[i][j] != 'x')
                look(b, b[i][j], {i, j});
        }
    }

    if (b[cur.first][cur.second] == 'x')
        return false;
    queue<pair<int, int>> q;
    q.push(cur);

    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        b[cur.first][cur.second] = 'h';
        for (int i = 0; i < 4; ++i)
        {
            int nr = cur.first + dir[i].first, nc = cur.second + dir[i].second;
            if (nr >= 0 && nc >= 0 && nr < n && nc < m && b[nr][nc] == '.')
                q.push({nr, nc});
        }
    }

    return (b[n - 1][m - 1] == 'h');
}

int main()
{
    // vector<string> b = {"X.....>", "..v..X.", ".>..X..", "A......"};
    // vector<string> b = {"...Xv", "AX..^", ".XX.."};
    // vector<string> b = {"...", ">.A"};
    vector<string> b = {"A.v", "..."};

    cout << guard(b) << endl;
    ;
}
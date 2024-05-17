#include <vector>
#include <iostream>
using namespace std;

#define ll long long

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int n, m;
vector<int> adj[MAX_N];
bool visited[MAX_N];

void dfs(int cur)
{
    visited[cur] = true;
    for (int neighbour : adj[cur])
    {
        if (!visited[neighbour])
        {
            dfs(neighbour);
        }
    }
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }
}
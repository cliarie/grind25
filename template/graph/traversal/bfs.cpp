
#define ll long long
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int n, m;
vector<int> adj[MAX_N];

// shortest path unweighted graph
void bfs(int start)
{
    queue<int> q;
    vector<int> dist(n + 1, -1);
    q.push(start);
    dist[start] = 0;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int neighbour : adj[cur])
        {
            if (dist[neighbour] == -1)
            {
                dist[neighbour] = dist[cur] + 1;
                q.push(neighbour);
            }
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
    bfs(1);
}
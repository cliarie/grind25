#include <iostream>
#include <vector>
#define ll long long

using namespace std;

struct Project
{
    int start, end, reward;
};

/*
MISSING ONE TEST CASE: time limit exceeded
dp[i] = maximum reward that can be obtained by doing projects from 0 to i where i is the last project
dp[i] = max(reward[i] + dp[j], dp[i - 1]) where j is the last project that ends before i starts
*/
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<Project> projects(n);
    for (int i = 0; i < n; ++i)
        cin >> projects[i].start >> projects[i].end >> projects[i].reward;

    sort(projects.begin(), projects.end(), [](Project a, Project b)
         { return a.end < b.end; }); // sort projects by end time

    vector<ll> dp(n, 0);
    dp[0] = projects[0].reward; // base case for first project
    for (int i = 1; i < n; ++i)
    {
        ll reward = projects[i].reward;
        int start = projects[i].start;

        int idx = -1;
        for (int j = i - 1; j >= 0; --j) // find the last project that ends before i starts
        {
            if (projects[j].end < start)
            {
                idx = j;
                break;
            }
        }
        if (idx != -1)
            reward += dp[idx];
        dp[i] = max(reward, dp[i - 1]);
    }
    // for (int i = 0; i < n; ++i)
    //     cout << dp[i] << " ";
    cout << dp[n - 1] << endl;
}
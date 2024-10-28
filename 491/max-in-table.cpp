#include <iostream>
#include <vector>
using namespace std;

/*
{1, 1, 1, 1, 1}
{1, 2, 3, 4, 5}
{1, 3, 6, 10, 15}
{1, 4, 10, 20, 35}
{1, 5, 15, 35, 70} n = 5 output = 70
*/
int main(){
    #ifdef LOCAL_TESTING
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for(int i = 0; i < n; i++){
        dp[i][0] = 1;
        dp[0][i] = 1;
    }

    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    cout << dp[n-1][n-1] << endl;
}

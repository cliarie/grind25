#include <iostream>
#include <vector>

const int inf = 1e9;

using namespace std;

/*
dp[i][j] = minimum cuts to cut i x j rectangle
dp[i][j] = min(dp[i][j-k])
*/
int main(){
    int a, b;
    cin >> a >> b;
    vector<vector<int>> dp(a+1, vector<int>(b+1, inf)); // minimum cuts to cut axb rectangle
    dp[1][1] = 0;
    for (int i = 1; i <= a; ++i){
        for (int j = 1; j <=b ; ++j){

        }
    }
}
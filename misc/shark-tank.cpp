#include <iostream>
#include <vector>
using namespace std;

double solve(int sharks, int tanks, vector<vector<double>> &p){
    int n = p.size();

    vector<vector<double>> dp(tanks + 1, vector<double>(sharks + 1)); // prob seeing shark with tank

    for (int t = 1; t <= tanks; ++t){
        for (int loc = 0; loc < n; ++loc){
            for (int s = sharks; s >= 0; --s){
                for (int i = 0; i < 6; ++i){
                    dp[t][s] = max(dp[t][s], dp[t - 1][s] * p[loc][i]);
                }
            }
        }
    }

    double ans = 0;
    for (int i = 0; i < n; ++i){
        double prob = 0;

    }
}

int main(){
    #ifdef LOCAL_TESTING
       freopen("../input.txt", "r", stdin);
       freopen("../output.txt", "w", stdout);
    #endif

    int sharks, tanks, locations;
    cin >> sharks >> tanks >> locations;
    vector<vector<double>> probabilities(locations, vector<double>(6, 0));
    for (int i = 0; i < locations; ++i){
        for (int j = 0; j < 6; ++j) cin >> probabilities[i][j];
    }

    cout << solve(sharks, tanks, probabilities);
}

#include <iostream>
#include <vector>
#include <utility>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main(){
    #ifdef LOCAL_TESTING
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    freopen("point.in", "r", stdin);
    freopen("point.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<pii> points(n);
    for (int i = 0; i < n; ++i){
        cin >> points[i].first >> points[i].second;
    }
    sort(points.begin(), points.end());

    vector<vector<int>> dp(n, vector<int>(k + 1, -1)); // max sequence length ending at i with k elements used
    for (int i = 0; i < n; ++i) dp[i][0] = 1;

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < i; ++j){
            if (points[j].first > points[i].first || points[j].second > points[i].second) continue;
            int dx = points[i].first - points[j].first;
            int dy = points[i].second - points[j].second;
            if (dx == 0 && dy == 0) continue;
            int additions = dx + dy - 1;
            for (int c = 0; c <= k - additions; ++c){
                if (dp[j][c] != -1){
                    dp[i][c + additions] = max(dp[i][c + additions], dp[j][c] + additions + 1);
                }
            }
        }
    }

    int maxSeq = 0;
    for (int i = 0; i < n; ++i){
        for (int c = 0; c <= k; ++c){
            if (dp[i][c] != -1){
                int more = dp[i][c] + (k - c);
                maxSeq = max(maxSeq, more);
            }
        }
    }
    cout << maxSeq << endl;
}

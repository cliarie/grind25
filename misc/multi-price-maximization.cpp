// given an array prices[] representing maximum prices buyer is willing to pay
// and n (max number of price points you can set), maximize total profit by selling at most n price points
// buyers buy at highest price point they are willing to pay

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int part1(vector<int> &prices){
    int n = prices.size();
    int ans = 0;
    int amt = 1;
    for (int i = n - 1; i >= 0; --i){
        ans = max(ans, prices[i] * amt);
        amt++;
    }
    return ans;
}

int part2(vector<int> &prices, int k){ // set at most k price points
    int n = prices.size();
    vector<vector<int> > dp(n + 1, vector<int>(k + 1, 0));
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= k; ++j){
            dp[i][j] = dp[i - 1][j];
            int curmin = prices[i - 1];
            for (int l = i - 1; l >= 0; --l){
                curmin = min(curmin, prices[l]);
                dp[i][j] = max(dp[i][j], dp[l][j - 1] + (i - l) * curmin);
            }
        }
    }
    return dp[n][k];
}

int part3(vector<int> &prices, int k, int l){ // set at most k price points, and sell at most l items
    vector<int> prices2(prices.end() - l, prices.end());
    int n = prices2.size();
    return part2(prices2, k);
}

// sort arr, then split arr into n subarrays such that smallest number in subarray * subarray length is maximized
int main(){
    #ifdef LOCAL_TESTING
       freopen("../input.txt", "r", stdin);
       freopen("../output.txt", "w", stdout);
    #endif

    int n, k, l; cin >> n >> k >> l;
    vector<int> prices(n, 0);
    for (auto &i : prices) cin >> i;
    sort(prices.begin(), prices.end());

    cout << part1(prices) << endl;
    cout << part2(prices, k) << endl;
    cout << part3(prices, k, l) << endl;

}

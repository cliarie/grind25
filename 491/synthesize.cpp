#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main(){
    #ifdef LOCAL_TESTING
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, p, q;
    cin >> a >> b >> p >> q;
    vector<long double> dp(a + 1, 0.0); // max expected val for num of problems
    long double p_c = p/100.0;
    long double q_l = q/100.0;
    if (b == 1) {
        for (int i = 1; i <= a; ++i) {
            dp[i] = max(dp[i - b] + (long double) 100 / (100 - q), dp[i - b] + ((long double)100 + p) / 100);
        }
    }
    else{
        for (int i = b; i <= a; ++i){
            long double char_v = p_c * (2 + dp[i - b]) + (1 - p_c) * (1 + dp[i - b]);
            // check bounds for letian if he uses b - 1 problems instead of b
            long double l_syn = 0.0;
            if (i - (b - 1) <= a){
                l_syn = dp[i - (b - 1)];
            }
            long double letian = q_l * (1 + l_syn) + (1 - q_l) * (1 + dp[i - b]);

            dp[i] = max(char_v, letian);
        }
    }

    cout << fixed << setprecision(15) << dp[a] << endl;
}

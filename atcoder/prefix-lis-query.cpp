
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define pii pair<int, int>
using namespace std;

template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  return os << '{' << p.first << ", " << p.second << '}';
}

template <class T, class = decay_t<decltype(*begin(declval<T>()))>,
          class = enable_if_t<!is_same<T, string>::value>>
ostream &operator<<(ostream &os, const T &c) {
  os << '[';
  for (auto it = c.begin(); it != c.end(); ++it)
    os << &", "[2 * (it == c.begin())] << *it;
  return os << ']';
}

int main(){
    #ifdef LOCAL_TESTING
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    s

    for(int test_case=1; test_case<=T; test_case++){
        int n, m, k;
        cin >> n >> m >> k;
        vector<pair<int, int>> intervals(m);
        for(int i=0; i<m; i++){
            cin >> intervals[i].first >> intervals[i].second;
        }

        vector<int> prefix(n + 1, 0);
        int longestend = 0;
        int cur = 0;
        for (int i = 0; i <= n; ++i){
            longestend = 0;
            cur = 0;
            for (int j = 0; j < m; ++j){
                if (intervals[j].first <= i && intervals[j].second > longestend){
                    cout << "i: " << i << " j: " << j << " longestend: " << longestend << " " << intervals[j].first << " " << intervals[j].second << endl;
                    longestend = intervals[j].second;
                    cur = j;
                }
            }
            prefix[i] = cur;
        }

        cout << prefix << endl;

        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
        for(int j_num = 1; j_num <= k; j_num++){
            for(int i = 1; i <= n; i++){
                dp[j_num][i] = dp[j_num][i - 1];

                if(prefix[i] != -1){
                    int interval_idx = prefix[i];
                    int L = intervals[interval_idx].first;
                    // Calculate the number of new days covered by this interval
                    // It's from day L to day i
                    // Since days are 1-based in DP, adjust indices accordingly
                    dp[j_num][i] = max(dp[j_num][i], dp[j_num - 1][L - 1] + (i - (L - 1)));
                }
            }
        }

        long long max_coverage = 0;
        for(int j_num = 0; j_num <= k; j_num++){
            max_coverage = max(max_coverage, (long long)dp[j_num][n]);
        }

        cout << "Case #" << test_case << ": " << max_coverage << "\n";
    }
}

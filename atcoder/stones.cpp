#include <iostream>
#include <ostream>
#include <vector>
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
  int n, k;
  cin >> n >> k;
  vector<int> a(k);
  vector<int> dp(n + 1, 0);
  for (int i = 0; i < k; ++i){
    cin >> a[i];
    dp[a[i]] = a[i];
  }
  // dp[i] = maximum first player can take with pile of n stones
  // dp[i] = a[k] + (i - a[k]) - (dp[i - a[k]] this is player 2)
  for (int i = 0; i <= n; ++i){
    for (int j = 0; j < k; ++j){
      if (i - a[j] <= 0) break;
      dp[i] = max(a[j] + (i - a[j]) - dp[i-a[j]], dp[i]);
//      dp[i] = a[j] + (i - a[j]) - (dp[i-a[j]]);
    }
  }


  // cannot take max at end
  // int maxxn = 0;
  // for (int i = 0; i <= n; ++i){
  //   cout << dp[i] << ' ';
  //   maxxn = max(maxxn, dp[i]);
  // }

  cout << dp[n] << '\n';
  // not greedy
  // int x, y; bool c = 1;
  // for (int i = k - 1; i >= 0 && n > 0; --i){
  //   int d = n / a[i];
  //   if (c) {
  //     x += ((d + 1)/ 2) * a[i];
  //   }
  //   else x += (d / 2) * a[i];
  //   if (d%2 != 0) c = !c;
  //   n -= d * a[i];
  // }
  //
  // cout << x;
  //
}

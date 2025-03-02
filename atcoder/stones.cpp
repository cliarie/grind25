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
  for (int i = 0; i < k; ++i){
    cin >> a[i];
  }
  
  int x, y; bool c = 1;
  for (int i = k - 1; i >= 0 && n > 0; --i){
    int d = n / a[i];
    if (c) {
      x += ((d + 1)/ 2) * a[i];
    }
    else x += (d / 2) * a[i];
    if (d%2 != 0) c = !c;
    n -= d * a[i];
  }

  cout << x << endl;

}

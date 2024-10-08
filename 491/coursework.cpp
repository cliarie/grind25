#include <iostream>
#include <vector>
#define ll long long

using namespace std;

int main(){
    #ifdef LOCAL_TESTING
       freopen("../input.txt", "r", stdin);
       freopen("../output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        int before = n - k + 1;

        long long s;
        cin >> s; // s_{n - k + 1}
        long long minPrev = LLONG_MIN;

        bool failed = false;
        long long cur;

        if (k > 1) {
            cin >> cur; // s_{n - k + 2}

            long long diff = cur - s; // a_{n - k + 2}

            // Check if s_{n - k + 1} ≤ (n - k + 1) × a_{n - k + 2}
            if (s > diff * before) {
                failed = true;
            }

            minPrev = diff;
            s = cur;

            for (int i = 2; i < k; i++) {
                cin >> cur;

                diff = cur - s;

                if (diff < minPrev) {
                    failed = true;
                }

                minPrev = diff;
                s = cur;
            }
        } else {
            // For k == 1, we don't need any checks
            failed = false;
        }

        if (failed) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}

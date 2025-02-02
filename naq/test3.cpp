#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int N;
    cin >> N;

    // Store challenge cards (Pk, Sk) in a set for quick lookup
    set<pair<int, int>> challenges;
    for (int i = 0; i < N; ++i) {
        int Pk, Sk;
        cin >> Pk >> Sk;
        challenges.insert({Pk, Sk});
    }

    // Store the generated pairs (pi, si)
    vector<pair<int, int>> characters;
    bool possible = true;

    // Use a set to track sums we've generated to avoid conflicts
    set<pair<int, int>> used_sums;

    // Generate N distinct pairs (pi, si)
    for (int i = 1; i <= N; ++i) {
        bool found = false;

        // Try different values for (pi, si) until we find a valid pair
        for (int pi = 1; pi <= N && !found; ++pi) {
            for (int si = 1; si <= N && !found; ++si) {
                // Check if using (pi, si) would create a conflicting sum
                bool conflict = false;

                for (const auto& [p, s] : characters) {
                    int sumP = pi + p;
                    int sumS = si + s;

                    if (challenges.count({sumP, sumS})) {
                        conflict = true;
                        break;
                    }
                }

                // If no conflict, use this pair
                if (!conflict) {
                    characters.emplace_back(pi, si);
                    used_sums.insert({pi, si});
                    found = true;
                }
            }
        }

        // If we couldn't find a valid pair, solution is impossible
        if (!found) {
            possible = false;
            break;
        }
    }

    // Output the result
    if (possible) {
        cout << "YES" << endl;
        for (const auto& p : characters) {
            cout << p.first << " " << p.second << endl;
        }
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

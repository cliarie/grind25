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

    // Generate candidate pairs (pi, si)
    vector<pair<int, int>> characters;
    for (int i = 1; i <= N; ++i) {
        characters.push_back({i, N - i + 1});
    }

    // Check if any two pairs (including identical pairs) result in a conflict
    bool possible = true;
    for (int i = 0; i < N; ++i) {
        for (int j = i; j < N; ++j) {
            int sumP = characters[i].first + characters[j].first;
            int sumS = characters[i].second + characters[j].second;

            // If there's a conflict with any (Pk, Sk), solution is impossible
            if (challenges.count({sumP, sumS})) {
                possible = false;
                break;
            }
        }
        if (!possible) break;
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

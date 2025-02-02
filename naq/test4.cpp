#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> challenges(N);
    set<pair<int, int>> challengeSet;

    // Reading the challenge cards
    for (int i = 0; i < N; ++i) {
        int P, S;
        cin >> P >> S;
        challenges[i] = {P, S};
        challengeSet.insert({P, S});
    }

    // Special case: If N == 1, there's no way to avoid overlap
    if (N == 1) {
        cout << "NO" << endl;
        return 0;
    }

    // Generate the (pi, si) pairs in a simple non-conflicting way
    vector<pair<int, int>> characters(N);
    for (int i = 0; i < N; ++i) {
        characters[i] = {i + 1, N - i};  // Assign distinct values
    }

    // Check if any generated pair's sum matches with a challenge card
    bool conflict = false;
    for (int i = 0; i < N; ++i) {
        for (int j = i; j < N; ++j) {
            int sumP = characters[i].first + characters[j].first;
            int sumS = characters[i].second + characters[j].second;

            if (challengeSet.count({sumP, sumS})) {
                conflict = true;
                break;
            }
        }
        if (conflict) break;
    }

    if (conflict) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (const auto &p : characters) {
            cout << p.first << " " << p.second << endl;
        }
    }

    return 0;
}

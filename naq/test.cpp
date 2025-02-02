#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Function to check if the given configuration is valid
bool isValid(const vector<pair<int, int>>& characters, const set<pair<int, int>>& challenges) {
    int N = characters.size();

    // Check sums for every pair (including same pairs twice)
    for (int i = 0; i < N; ++i) {
        for (int j = i; j < N; ++j) {
            int sumP = characters[i].first + characters[j].first;
            int sumS = characters[i].second + characters[j].second;

            // If any sum matches a challenge card, return false
            if (challenges.count({sumP, sumS})) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int N;
    cin >> N;

    // Store the challenge cards (Pk, Sk) in a set for quick lookup
    set<pair<int, int>> challenges;
    for (int i = 0; i < N; ++i) {
        int Pk, Sk;
        cin >> Pk >> Sk;
        challenges.insert({Pk, Sk});
    }

    // Generate an initial valid configuration of pairs
    vector<pair<int, int>> characters;
    for (int i = 1; i <= N; ++i) {
        characters.push_back({i, (i % N) + 1});
    }

    // Check if the generated configuration is valid
    if (isValid(characters, challenges)) {
        cout << "YES" << endl;
        for (const auto& p : characters) {
            cout << p.first << " " << p.second << endl;
        }
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
    #ifdef LOCAL_TESTING
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;

    vector<vector<long long>> dist(n, vector<long long>(n));
    long long temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> temp;
            dist[i][j] = temp;
        }
    }

    int k;
    cin >> k;

    long long curtotal = 0;

    // Compute initial total sum of shortest paths
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            curtotal += dist[i][j];
        }
    }

    for (int i = 0; i < k; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        a--;
        b--;

        if (c >= dist[a][b]) {
            cout << curtotal << " ";
            continue;
        }

        // Create a copy of the current distances to store updated values
        vector<vector<long long>> new_dist = dist;

        // Update the distance between a and b
        new_dist[a][b] = new_dist[b][a] = c;

        long long delta = 0;

        // Update distances using a and b as intermediate nodes
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                long long old_dist = dist[x][y];
                long long via_a_b = dist[x][a] + c + dist[b][y];
                long long via_b_a = dist[x][b] + c + dist[a][y];
                long long new_d = min({new_dist[x][y], via_a_b, via_b_a});

                if (new_d < new_dist[x][y]) {
                    new_dist[x][y] = new_d;
                }

                // Update delta only for unordered pairs
                if (x < y && new_dist[x][y] < old_dist) {
                    delta += new_dist[x][y] - old_dist;
                }
            }
        }

        // Update the main distance matrix
        dist = new_dist;

        // Update the current total sum of distances
        curtotal += delta;

        cout << curtotal << " ";
    }

    return 0;
}

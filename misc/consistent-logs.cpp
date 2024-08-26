#include <vector>
#include <iostream>
#include <unordered_map>
#include <limits.h>
using namespace std;

int findConsistentLogs(vector<int> userEvent) {
    unordered_map<int, int> freq;
    int minf = INT_MAX;
    for (auto &log : userEvent)
        freq[log]++;
    for (auto l : freq)
        minf = min(minf, l.second);
    int len = 0;

    unordered_map<int, int> temp;
    int j = 0;
    for (int i = 0; i < userEvent.size(); ++i){
        temp[userEvent[i]]++;
        while(temp[userEvent[i]] > minf){
            temp[userEvent[j]]--;
            j++;
        }
        len = max(len, i - j + 1);
    }

    return len;
}

int main() {
    #ifdef LOCAL_TESTING
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif
    int n; cin >> n;
    vector<int> userEvent(n);
    for (int i = 0; i < n; ++i) cin >> userEvent[i];
    cout << findConsistentLogs(userEvent) << endl;
    return 0;
}

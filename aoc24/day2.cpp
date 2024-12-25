#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

int part1(vector<vector<int>> &a){
    int sum = 0;
    for (auto v : a){
        int n = v.size();
        int dir = (v[1] - v[0] > 0);
        for (int i = 1; i < n; ++i){
            int diff = v[i] - v[i - 1];
            if (dir && diff >= 1 && diff <= 3){
                if (i == n - 1) sum++;
            }
            else if (!dir && diff <= -1 && diff >= -3){
                if (i == n - 1) sum++;
            }
            else break;
        }
    }
    return sum;
}

int part2(vector<vector<int>> &a){
    int sum = 0;
    for (auto v : a){
        int count = 0, index = -1;
        int n = v.size();
        if (n < 2) {
            sum++;
            continue;
        }
        int dir = (v[1] - v[0] > 0);
        for (int i = 1; i < n; ++i){
            int diff = v[i] - v[i - 1];
            bool valid_diff = dir ? (diff >= 1 && diff <= 3) : (diff <= -1 && diff >= -3);
            if (!valid_diff){
                count++;
                index = i;
                if (count > 1) break;
            }
        }
        if (count == 0) sum++;
        else if (count == 1){
            cout << index << " " << count << endl;
            if (index == n - 1 || index == 1) sum++;
            else {
                int diff = v[index + 1] - v[index - 1];
                if (dir ? (diff >= 1 && diff <= 3) : (diff <= -1 && diff >= -3)) {
                    sum++;
                    continue;
                }
                    diff = v[index - 1] - v[index - 2]; // typo but it works?
                    if (dir ? (diff >= 1 && diff <= 3) : (diff <= -1 && diff >= -3)) sum++;
                }
            }
        }
    }
    return sum;
}

int main(){
    #ifdef LOCAL_TESTING
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<int>> a;
    string line;
    while(getline(cin, line)){
        stringstream ss(line);
        int x;
        vector<int> b;
        while (ss >> x) b.push_back(x);
        a.push_back(b);
    }

    cout << part1(a) << endl;
    cout << part2(a) << endl;

}

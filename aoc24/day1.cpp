#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

int part1(vector<int> &a, vector<int> &b){
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int sum = 0;
    int n = a.size();
    for (int i = 0; i < n; ++i) sum += (a[i] > b[i]) ? a[i] - b[i] : b[i] - a[i];
    return sum;
}

int part2(vector<int> &a, vector<int> &b){
    unordered_map<int, int> m;
    int n = b.size();
    for (auto i : b) m[i]++;
    int sum = 0;
    for (auto i : a) sum += i * m[i];
    return sum;
}

int main(){
    #ifdef LOCAL_TESTING
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> a, b;
    string line;
    while(getline(cin, line)){
        stringstream ss(line);
        int x, y;
        ss >> x >> y;
        a.push_back(x);
        b.push_back(y);
    }

    cout << part1(a, b) << endl;
    cout << part2(a, b) << endl;

}

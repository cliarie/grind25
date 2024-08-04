#include <iostream>
#include <string>
#include <set>

using namespace std;

bool ishappy(string &word){
    set<int> s;
    string cur = word;
    while (true){
        if (s.find(stoi(cur)) != s.end()) return false;
        s.insert(stoi(cur));
        int sum = 0;
        for (char c : cur){
            sum += (c - '0') * (c - '0');
        }
        if (sum == 1) return true;
        cur = to_string(sum);
    }
}

int main() {
#ifdef LOCAL_TESTING
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    string line;
    while (getline(cin, line)) {
        cout << ishappy(line) << endl;
    }

    return 0;
}

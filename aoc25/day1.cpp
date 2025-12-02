#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int part1(vector<string> &a){
    int cur = 50;
    int ans = 0;
    for (auto &s : a){
        if (s[0] == 'L') cur -= stoi(s.substr(1));
        else cur += stoi(s.substr(1));
        cur = (cur +100) % 100;
        if (!cur) ans++;
    }
    return ans;
}

int part2(vector<string> &a){
    int cur = 50, prev = 50;
    int ans = 0;
    for (auto &s : a){
        if (s[0] == 'L') cur -= stoi(s.substr(1));
        else cur += stoi(s.substr(1)); 
        int count = cur > 0 ? (cur / 100) : abs(cur - 100) / 100;
        if (cur <= 0 && prev == 0) count--;
        ans += count;
        cur = (cur % 100 +100) % 100;
        prev = cur;
    }
    return ans;
}

int main(){
    #ifdef LOCAL_TESTING
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<string> a;
    string line;
    while(getline(cin, line)){
        stringstream ss(line);
        string b;
        ss >> b;
        a.push_back(b);
    }

    cout << part1(a) << endl;
    cout << part2(a) << endl;

}
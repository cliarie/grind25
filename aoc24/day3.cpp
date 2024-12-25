#include <regex>
#include <iostream>
using namespace std;

int part1(string &s){
    regex r("mul\\(([0-9]{1,3}),([0-9]{1,3})\\)");
    smatch m;
    int sum = 0;
    while (regex_search(s, m, r)){
        int a = stoi(m[1]);
        int b = stoi(m[2]);
        int c = a * b;
        sum += c;
        s = m.suffix();
    }
    return sum;
}

int part2(string &s){
    regex r("(do\\(\\)|don't\\(\\))|mul\\(([0-9]{1,3}),([0-9]{1,3})\\)");
    smatch m;
    int sum = 0;
    bool flag = true;
    while (regex_search(s, m, r)){
        if (!m[1].str().empty()){
            string action = m[1];
            if (action == "do()") flag = true;
            else if (action == "don't()") flag = false;
        }
        else if (flag && m[2].matched && m[3].matched){
            int a = stoi(m[2]);
            int b = stoi(m[3]);
            int c = a * b;
            sum += c;
        }
        s = m.suffix();
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
    string line, s;
    while(getline(cin, line)){
        s += line;
    }
    // cout << part1(s) << endl;
    cout << part2(s) << endl;
}

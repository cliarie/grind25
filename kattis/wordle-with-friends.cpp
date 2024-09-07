#include <iostream>
#include <unordered_set>
#include <vector>
#include <unordered_map>
using namespace std;

bool valid(string &s, string &guess, unordered_set<char> &noinclude, unordered_map<char, int> minfreq, vector<unordered_set<char>> &guessed){
    for (int i = 0; i < s.length(); ++i){
        char c = s[i];
        if (guess[i] != '-' && c != guess[i]) return false; // greens don't match
        if (noinclude.count(c)) return false;
        if (guessed[i].count(c)) return false;
        --minfreq[c];
    }
    for (auto &[c, count] : minfreq){
        if (count > 0) return false;
    }
    return true;
}

int main(){
    #ifdef LOCAL_TESTING
       freopen("../input.txt", "r", stdin);
       freopen("../output.txt", "w", stdout);
    #endif
    int n, w;
    cin >> n >> w;

    string G(5, '-');
    unordered_set<char> noinclude;
    unordered_map<char, int> minfreq;
    vector<unordered_set<char>> guessed(5);
    for (int i = 0; i < n; ++i){
        string g, f; cin >> g >> f;
        unordered_map<char, int> req;
        for (int j = 0; j < f.length(); ++j){
            char c = g[j];
            if (f[j] == 'G'){
                G[j] = c;
                ++req[c];
            }
            else if (f[j] == 'Y'){
                ++req[c];
                guessed[j].insert(c);
            }
            else if (f[j] == '-'){
                noinclude.insert(c);
                guessed[j].insert(c);
            }
        }
        for (auto &[c, count] : req){
            noinclude.erase(c);
            minfreq[c] = max(minfreq[c], count);
        }
    }

    for (int i = 0; i < w; ++i){
        string s; cin >> s;
        if (valid(s, G, noinclude, minfreq, guessed)) cout << s << endl;
    }
}

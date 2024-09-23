#include <iostream>
#include <vector>
using namespace std;

// dsu union by rank
int find(int a, vector<int> &parent){
    if (a != parent[a]){
        parent[a] = find(parent[a], parent);
    }
    return parent[a];
}

int main(){
    #ifdef LOCAL_TESTING
       freopen("../input.txt", "r", stdin);
       freopen("../output.txt", "w", stdout);
    #endif

    int n; cin >> n;
    vector<bool> seen(26, false);
    vector<int> parent(26);
    for (int i = 0; i < 26; ++i) parent[i] = i;

    for (int i = 0; i < n; ++i){
        string s; cin >> s;
        for (int j = 0; j < s.length(); ++j){
            seen[s[j] - 'a'] = true;
            int rep = find(s[j] - 'a', parent);
            if (j != 0) {
                int prep = find(s[j - 1] - 'a', parent);
                parent[rep] = prep;
            }
        }
    }

    int count = 0;
    for (int i = 0; i < 26; ++i){
        // cout << parent[i] << seen[i] << endl;
        if (seen[i] == 1 && parent[i] == i) count++;
    }

    cout << count << endl;
}

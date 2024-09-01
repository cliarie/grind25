#include <iostream>

#include <unordered_map>
using namespace std;

int main(){
 #ifdef LOCAL_TESTING
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
 #endif
    int n, m;
    cin >> n >> m;
    unordered_map<string, string> serverm;
    for (int i = 0; i < n; ++i){
        string name, ip;
        cin >> name >> ip;
        serverm[ip] = name;
    }
    for (int i = 0; i < m; ++i){
        string command, ip;
        cin >> command >> ip;
        cout << command + " " + ip + " #" + serverm[ip.substr(0, ip.length() - 1)] << endl;
    }
}

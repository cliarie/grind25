#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>

using namespace std;


int main() {
#ifdef LOCAL_TESTING
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    string first, second;
    string start, end;
    map<string, vector<string>> graph;
    getline(cin, start, '/');
    getline(cin, end);

    while (getline(cin, first, '/') && getline(cin, second)) {
        graph[first].push_back(second);
        graph[second].push_back(first);
    }
    int level = 0;
    queue<string> q;
    map<string, string> parent;
    q.push(start);
    parent[start] = "";
    while (!q.empty()) {
        int size = q.size();
        while(size--){
            string current = q.front();
            q.pop();
            if (current == end) {
                break;
            }
            for (string next : graph[current]) {
                if (parent.find(next) == parent.end()) {
                    parent[next] = current;
                    q.push(next);
                }
            }
        }
        level++;
    }
    cout << level - 1 << endl;
    return 0;
}

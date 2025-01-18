#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;

void processInput(vector<pii> &pairs, vector<vi> &lists){
    string line;
    while (getline(cin, line)){
        if (line.find('|') != string::npos){
            istringstream lstream(line);
            int a, b;
            char delim;
            lstream >> a >> delim >> b;
            pairs.push_back({a, b});
        } else if (line.find(',') != string::npos){
            vector<int> list;
            istringstream lstream(line);
            string num;
            while (getline(lstream, num, ',')){
                if (num != "") list.push_back(stoi(num));
            }
            lists.push_back(list);
        }
    }
}

void toposort(int x, vector<int> &order, unordered_map<int, vi> &edges, set<int> &cur, unordered_map<int, int> &indeg){
    order.push_back(x);
    for (int a : edges[x]){
        if (cur.count(a)){
            if (--indeg[a] == 0){
                toposort(a, order, edges, cur, indeg);
            }
        }
    }
}

int part2(vector<pii> &pairs, vector<vi> &lists){
    unordered_map<int, vi> edges;
    for (auto [a, b] : pairs){
        edges[a].push_back(b);
    }

    int ans = 0;
    for (auto list : lists){
        bool valid = true;
        unordered_map<int, int> indeg;
        set<int> cur;
        for (auto i : list) cur.insert(i);

        set<int> prev;
        for (int a : list){
            for (int b : edges[a]){
                if (cur.count(b))
                    indeg[b]++;
                if (prev.count(b)){
                    valid = false;
                    // break;
                }
            }
            prev.insert(a);
        }


        int mid = static_cast<int>(list.size()/2);
        if (!valid) {
            vi order;
            vi starting;
            for (int x : cur){
                cout << "IN " << x << " " << indeg[x] << endl;
                if (indeg[x] == 0){
                    starting.push_back(x);
                }
            }
            for (auto s : starting) toposort(s, order, edges, cur, indeg);
            for (auto x : order) cout << x << " ";
            cout << endl;
            cout << order[mid] << endl;
            ans += order[mid];
        }
    }
    return ans;
}

int part1(vector<pii> &pairs, vector<vi> &lists){
    int ans = 0;
    for (auto list : lists){
        bool valid = true;
        for (auto [a, b] : pairs){
            // for (auto l : list){
            //     cout << l << " ";
            // }
            // cout << endl;
            auto ita = find(list.begin(), list.end(), a);
            auto itb = find(list.begin(), list.end(), b);
            // cout << ita - list.begin() << " " << itb - list.begin() << endl;
            if (ita != list.end() && itb != list.end() && (ita - list.begin()) > (itb - list.begin())) {
                valid = false;
                break;
            }
        }
        int mid = static_cast<int>(list.size()/2);
        if (valid) {
            // for (auto i : list) cout << i << " ";
            // cout << endl;
            // cout << list[mid] << endl;
            ans += list[mid];
        }
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

    vector<pii> pairs;
    vector<vi> lists;

    processInput(pairs, lists);

    cout << part1(pairs, lists) << endl;
    cout << part2(pairs, lists) << endl;
}

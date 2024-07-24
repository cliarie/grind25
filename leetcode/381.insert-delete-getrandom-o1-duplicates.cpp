#include <iostream>
#include <vector>
#include <map>
using namespace std;
class RandomizedCollection {
public:
    // m[5] = {1, 2, 3}
    // v[1] = {5, 0}
    // v[3] = {5, 2}
    unordered_map<int, vector<int>> m; // maps val to a list of vector indices
    vector<pair<int, int>> v; // vector indices correspond to value in map and position in map[val]
    RandomizedCollection() {
    }
    
    bool insert(int val) {
        bool ret = (m[val].size() == 0);
        m[val].push_back(v.size());
        pair<int, int> p = {val, m[val].size() - 1};
        v.push_back(p);
        return ret;
    }
    
    bool remove(int val) {
        int last = v.size() - 1;
        if (m[val].size() == 0) return false;
        int tor = m[val].back();
        m[v[last].first][v[last].second] = tor; // make sure there are no gaps in indices
        v[tor] = v[last];
        m[val].pop_back();
        if (m[val].size() == 0) m.erase(val);
        v.pop_back();
        // erase vector index corresponding to tor

        // auto last = v.size() - 1;
        // m[v[last].first][v[last].second] = tor;

        // v[tor] = v[last];
        // cout << tor << " " << last << endl;
        //         for (auto d : m){
        //     for (auto e : d.second) cout << d.first << "m " << e << " ";
            // cout << endl;
        // // }
        // v.pop_back();
        // cout << val  << endl;
        // for (auto d : v) cout << d.first << " " <<  d.second << endl;
        return true;
    }
    
    int getRandom() {
        int i = rand() % v.size();
        // for (auto d : m){
        //     for (auto e : d.second) cout << d.first << " " << e << " ";
        //     cout << endl;
        // }
        // cout << "NOW V" << endl;
        // for (auto d : v) cout << d.first << " " <<  d.second << endl;
        return v[i].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

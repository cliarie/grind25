class RandomizedSet {
public:
    unordered_map<int, int> m;
    vector<int> v;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (m.find(val) != m.end()) return false; // alr exists
        v.push_back(val);
        m[val] = v.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (m.find(val) == m.end()) return false;
        int vectindex = m[val];
        cout << val << " " << vectindex << endl;
        v[vectindex]=v[v.size() -1];
        m[v[v.size() - 1]] = vectindex;
        v.pop_back();
        m.erase(val);

        return true;
    }
    
    int getRandom() {
       int i = rand() % v.size(); 
       cout << i << endl;
       return v[i];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

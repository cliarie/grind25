class LRUCache {
public:
    unordered_map<int, list<pair<int, int>>::iterator> m_map; // key -> list iterator of <key, val>
    list<pair<int, int>> m_list;
    int capacity;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        auto it = m_map.find(key);
        if (it == m_map.end()) return -1;
        int val = it->second->second;

        m_list.erase(it->second);
        m_list.push_front({key, val});

        m_map[key] = m_list.begin();
        return val;
    }

    void put(int key, int value) {
        auto it = m_map.find(key);
        if (it != m_map.end()){
            m_list.erase(it->second);
        }

        m_list.push_front({key, value});
        m_map[key] = m_list.begin();

        if (m_map.size() > capacity){ // pop lru
            int key = m_list.rbegin()->first;
            m_map.erase(m_map.find(key));
            m_list.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

class TrieNode{
public:
    TrieNode* child[26];
    bool isEnd;
    TrieNode(){
        isEnd = false;
        for (auto &n : child) n = nullptr;
    }
};

class StreamChecker {
private:
    TrieNode* head = new TrieNode();
    string stream = "";
public:
    void insert(string &word){
        auto cur = head;
        for (auto &c : word){
            if (cur->child[c - 'a'] == nullptr) cur->child[c - 'a'] = new TrieNode();
            cur = cur->child[c - 'a'];
        }
        cur->isEnd = true;
    }
    
    bool find(string &word){
        auto cur = head;
        for (auto &c : word){
            if (!cur->child[c-'a']) return false;
            cur = cur->child[c-'a'];
            if (cur->isEnd) return true;
        }
        return false;
    }

    StreamChecker(vector<string>& words) {
        for (auto &w : words){
            reverse(w.begin(), w.end());
            insert(w);
        }
    }
    
    bool query(char letter) {
        stream = letter + stream;
        return find(stream);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */


class TrieNode{
public:
    TrieNode *child[26];
    bool isEnd;
    TrieNode(){
        isEnd = false;
        for (auto &c : child) c = nullptr;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *cur = root;
        for (auto &c : word){
            int i = c - 'a';
            if (cur->child[i] == nullptr) cur->child[i] = new TrieNode();
            cur = cur->child[i];
        }
        cur->isEnd = true;

    }
    
    bool search(string word) {
        TrieNode *cur = root;
        for (auto &c : word){
            int i = c - 'a';
            if (cur->child[i] == nullptr) return false;
            cur = cur->child[i];
        }
        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode *cur = root;
        for (auto &c : prefix){
            int i = c - 'a';
            if (cur->child[i] == nullptr) return false;
            cur = cur->child[i];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

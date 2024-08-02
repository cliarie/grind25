#include <string>
using namespace std;
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
        for (int i = word.size() - 1; i >= 0; i--){
            if (cur->child[word[i] - 'a'] == nullptr) cur->child[word[i] - 'a'] = new TrieNode();
            cur = cur->child[word[i] - 'a'];
        }
        cur->isEnd = true;
    }

    bool find(string &word){
        auto cur = head;
        for (int i = word.size() - 1; i >= 0; i--){
            if (!cur->child[word[i]-'a']) return false;
            cur = cur->child[word[i]-'a'];
            if (cur->isEnd) return true;
        }
        return false;
    }

    StreamChecker(vector<string>& words) {
        for (auto &w : words){
            insert(w);
        }
    }

    bool query(char letter) {
        stream += letter;
        return find(stream);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */

#include <vector>
#include <string>
using namespace std;
class TrieNode{
public:
    TrieNode* child[26];
    string word;
    bool end;
    TrieNode(){
        end = false; word = "";
        for (auto &c : child) c = nullptr;
    }
};
class Trie{
private:
    TrieNode* root;
public:
    Trie(vector<string> &words){
        root = new TrieNode();
        for (auto &s : words) insert(s);
    }
    TrieNode* getroot() {return root;}

    void insert(string &word){
        auto cur = root;
        for (auto &c : word){
            int i = c - 'a';
            if (!cur->child[i]) cur->child[i] = new TrieNode();
            cur = cur->child[i];
        }
        cur->word = word;
        cur->end = true;
    }
};
class Solution {
public:
vector<vector<char>> board;
vector<string> words;
int n, m;
vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
// dfs + trie
    bool inbounds(pair<int, int> &p){
        return p.first >= 0 && p.second >= 0 && p.first < n && p.second < m;
    }

    void dfs(TrieNode* curnode, pair<int, int> &curpos, set<string> &ans){
        char c = board[curpos.first][curpos.second];
        if (c == '-' || !curnode->child[c - 'a']) return;
        curnode = curnode->child[c - 'a'];
        if (curnode->end) {ans.insert(curnode->word);}
        board[curpos.first][curpos.second] = '-';
        for (auto p : dirs){
            pair<int, int> next = {curpos.first + p.first, curpos.second + p.second};

            if (inbounds(next)) dfs(curnode, next, ans);
        }
        board[curpos.first][curpos.second] = c;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* trie = new Trie(words);
        TrieNode* root = trie->getroot();
        this->board = board;
        this->words = words;
        n = board.size(); m = board[0].size();

        set<string> ans;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                pair<int, int> bruh = make_pair(i, j);
                dfs(root, bruh, ans);
            }
        }
        vector<string> bruh4;
        for (auto bruh3 : ans) bruh4.push_back(bruh3);
        return bruh4;
    }
};

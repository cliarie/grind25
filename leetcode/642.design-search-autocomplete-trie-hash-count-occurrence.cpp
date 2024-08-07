#include <map>
#include <string>
#include <queue>
using namespace std;

class TrieNode{
public:
    unordered_map<char, TrieNode*> children;
    unordered_map<string, int> heat; // node stores strings associated with
};

class Compare{
public:
    bool operator() (pair<int, string> a, pair<int, string> b){
        if (a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    }
};

class AutocompleteSystem {
private:
    string curs = "";
    TrieNode* head = new TrieNode();

    void add(string s, int h){
        auto cur = head;
        for (auto c : s){
            if (!cur->children[c]) cur->children[c] = new TrieNode();
            cur = cur->children[c];
            cur->heat[s] += h;
        }
    }

public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        int n = sentences.size();
        for (int i = 0; i < n; ++i){
            add(sentences[i], times[i]);
        }
    }

    vector<string> input(char c) {
        vector<string> ans; int t = 3;
        if (c == '#'){
            add(curs, 1);
            curs = "";
            return {};
        }
        curs += c;
        TrieNode* cur = head;
        for (auto ch : curs){
            if (!cur->children[ch]) return ans;
            cur = cur->children[ch];
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> pq;
        for (auto e : cur->heat){
            pq.push({e.second, e.first});
        }

        while(!pq.empty() && t--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */

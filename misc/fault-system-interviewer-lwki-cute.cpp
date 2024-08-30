#include <iostream>
#include <unordered_map>
#include <set>
#include <jsoncpp/json/json.h>

using namespace std;

class TrieNode{
  public:
  unordered_map<string, TrieNode*> children;
  bool isEnd = false;
};

class FaultDetection{
private:
  TrieNode *head = new TrieNode();
  set<string> faults;

  void add(vector<string> &network){
    auto cur = head;
    for (int i = 0; i < network.size(); ++i){
      if (!cur->children[network[i]]){
        cur->children[network[i]] = new TrieNode();
      }
      cur = cur->children[network[i]];
      if (i == network.size() - 1) {
        cur->isEnd = true;
      }
    }
  }

  void traverseTree(TrieNode *cur, string curpath){
    if (cur->isEnd){
      faults.insert(curpath.substr(1));
      return;
    }
    for (auto it = cur->children.begin(); it != cur->children.end(); ++it){
      if (it->second){
        string nextpath = curpath + "/" + it->first;
        traverseTree(it->second, nextpath);
      }
    }
  }

public:
  vector<string> faultDetectionSystem(vector<string> &network){
    for (auto &str : network){
      vector<string> nodes;
      int pos = 0;
      string node;
      while((pos = str.find('/')) != string::npos){
        node = str.substr(0, pos);
        nodes.push_back(node);
        str.erase(0, pos + 1);
      }
      nodes.push_back(str);
      add(nodes);
    }

    head->isEnd = false;
    traverseTree(head, "");

    vector<string> ans;
    for (auto &s : faults){
      ans.push_back(s);
    }
    return ans;

  }

};

int main() {
  cout << "INPUT 1" << endl;
  vector<string> input = {"/o1/s1/c1", "/o1/s1/c2", "/o1/s2/c2", "/o1/s1"};
  FaultDetection fd = FaultDetection();
  vector<string> ans = fd.faultDetectionSystem(input);
  for (auto& str : ans){
    cout << str << endl;
  }

  cout << "INPUT 2 " << endl;
  input = {"/o1/s1/c1", "/o1/s1/c12", "/o1/s1/c3"};
  FaultDetection fd2 = FaultDetection();
  ans = fd2.faultDetectionSystem(input);
  for (auto& str : ans){
    cout << str << endl;
  }
  return 0;
}

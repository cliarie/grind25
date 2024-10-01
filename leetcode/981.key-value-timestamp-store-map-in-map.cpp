#include <string>
#include <map>
using namespace std;
class TimeMap {
public:
    unordered_map<string, map<int, string>> m;
    TimeMap() {
    }

    void set(string key, string value, int timestamp) {
        m[key].insert({timestamp, value});
    }

    string get(string key, int timestamp) {
        auto it = m[key].upper_bound(timestamp);
        if (it == m[key].begin()) return "";
        return prev(it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

 class TimeMap {
 public:
     unordered_map<string, vector<pair<int, string>>> timemap;
     TimeMap() {

     }

     void set(string key, string value, int timestamp) {
         timemap[key].push_back({timestamp, value});
     }

     string get(string key, int timestamp) {
         if (timemap.find(key) == timemap.end()) return "";
         pair<int, string> target = {timestamp, "~"};
         auto it = upper_bound(timemap[key].begin(), timemap[key].end(), target);
         if (it == timemap[key].begin()) return "";
         return prev(it)->second;
     }
 };

 /**
  * Your TimeMap object will be instantiated and called as such:
  * TimeMap* obj = new TimeMap();
  * obj->set(key,value,timestamp);
  * string param_2 = obj->get(key,timestamp);
  */

class TimeStamp{
public:
    string timestamp;
    unordered_map<string, string> gran;
    TimeStamp(string &s){
        timestamp = s;
        gran["Year"] = s.substr(0, 4);
        gran["Month"] = s.substr(0, 7);
        gran["Day"] = s.substr(0, 10);
        gran["Hour"] = s.substr(0, 13);
        gran["Minute"] = s.substr(0, 16);
        gran["Second"] = s.substr(0, 19);
    };
    bool operator==(const auto& other) const {return timestamp == other.timestamp;}
};

class LogSystem {
public:
    unordered_map<int, string> logs;
    vector<pair<TimeStamp, int>> timestamps;
    LogSystem() {
        // hashmap map id to timestamp override timestamp if already present
        // map timestamp to id where timestamp is a struct that is sorted by year then day
    }
    
    void put(int id, string timestamp) {
        logs[id] = timestamp;
        TimeStamp t = TimeStamp(timestamp);
        for (auto ts : timestamps){
            if (ts.first == t && ts.second == id) return;
        }
        timestamps.push_back(make_pair(t, id));
    }
    
    vector<int> retrieve(string start, string end, string granularity) {
        TimeStamp s = TimeStamp(start);
        TimeStamp e = TimeStamp(end);

        vector<int> ans;
        for (auto ts : timestamps){
            auto t = ts.first;
            if (t.gran[granularity] >= s.gran[granularity] && t.gran[granularity] <= e.gran[granularity]){
                ans.push_back(ts.second);
            }
        }

        return ans;
    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(start,end,granularity);
 */

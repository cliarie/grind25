class Solution {
public:
    struct Log{
        int id;
        bool start;
        int timestamp;
    };

    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n);

        int prev = 0;
        stack<Log> funcstack;
        for (auto log : logs){
            stringstream ss(log);
            string id, timestamp, start;
            getline(ss, id, ':');
            getline(ss, start, ':');
            getline(ss, timestamp, ':');
            Log item;
            if (start == "start") item = {stoi(id), true, stoi(timestamp)};
            else item = {stoi(id), false, stoi(timestamp)};

            if (item.start){
                if (funcstack.size()){
                    ans[funcstack.top().id] += item.timestamp - prev;
                }
                funcstack.push(item);
                prev = item.timestamp;
            } else{
                Log started = funcstack.top();
                funcstack.pop();
                int time = item.timestamp - prev;
                ans[item.id] += time + 1;
                prev = item.timestamp + 1;
            }
        }

        return ans;
    }
};

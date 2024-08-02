#include <iostream>
#include <deque>
#include <vector>
using namespace std;

class LogServer {
public:
    LogServer(int m) : m(m) {}

    void recordLog(int logId, int timestamp) {
        if (!logs.empty() && timestamp <= logs.back().first) {
            return;
        }
        logs.push_back({timestamp, logId});
        while (logs.front().first <= logs.back().first - 3600) {
            logs.pop_front();
        }
    }

    string getLogs() {
        vector<string> recent_logs;
        int cnt = m;
        while (cnt > 0 && cnt <= logs.size()) {
            recent_logs.push_back(to_string(logs[logs.size() - cnt].second));
            cnt--;
        }
        string ans = "";
        for (size_t i = 0; i < recent_logs.size(); ++i) {
            if (i != 0) {
                ans += ",";
            }
            ans += recent_logs[i];
        }
        return ans;
    }

    int getLogCount() const {
        return logs.size();
    }

private:
    int m;
    deque<pair<int, int>> logs;
};

int main() {
    LogServer server(2);
    server.recordLog(1, 0);
    server.recordLog(7, 600);
    server.recordLog(3, 1200);
    server.recordLog(5, 1800);
    cout << server.getLogs() << endl;
    cout << server.getLogCount() << endl;
    server.recordLog(2, 2400);
    cout << server.getLogs() << endl;
    cout << server.getLogCount() << endl;
    return 0;
}

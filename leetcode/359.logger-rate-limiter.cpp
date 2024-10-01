class Logger {
public:
    unordered_map<string, int> loggermap;
    Logger() {

    }

    bool shouldPrintMessage(int timestamp, string message) {
        if (loggermap.find(message) != loggermap.end()){
            if (timestamp >= loggermap[message]){
                loggermap[message] = timestamp + 10;
                return true;
            }
            else return false;
        }
        loggermap[message] = timestamp + 10;
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */

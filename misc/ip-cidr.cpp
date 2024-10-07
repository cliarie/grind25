#include <iostream>
#include <sstream>
#include <bitset>
#include <utility>
using namespace std;

// convert into 32 bit integer
uint32_t ipToInt(string &ip){
    uint32_t res;
    int octet;
    char dot;
    stringstream ss(ip);

    for (int i = 0; i < 4; ++i){
        ss >> octet;
        res = (res << 8) + octet;
        if (i < 3) ss >> dot;
    }
    return res;
}

pair<uint32_t, uint32_t> parseRule(vector<string> &rule){
    string ip = rule[1];

    int prefix = 32;
    int slash = ip.find('/');

    if (slash != string::npos) {
        prefix = stoi(ip.substr(slash + 1));
        ip = ip.substr(0, slash);
    }
    uint32_t ipBin = ipToInt(ip);
    uint32_t mask;
    if (prefix == 0) mask = 0;
    else mask = 0xFFFFFFFF << (32 - prefix);

    return {ipBin, mask};
}

string isAllowed(string &ip, vector<vector<string>> &rules){
    uint32_t binIp = ipToInt(ip);
    for (auto &rule : rules){
        auto [binNet, mask] = parseRule(rule);
        if ((binIp & mask) == (binNet & mask)) return rule[0];
    }
    return "DENY";
}


int main(){
    string ip = "121.0.0.8";
    uint32_t binIp = ipToInt(ip);
    cout << binIp << endl;

    vector<vector<string>> rules = {{"ALLOW", "192.168.1.0/24"}, {"ALLOW", "1.2.3.4"}, {"DENY", "10.5.12.10/28"}};
    cout << isAllowed(ip, rules) << endl;

    ip = "192.168.1.5";
    rules = {{"ALLOW", "192.168.1.0/24"},
    {"DENY", "10.5.12.0/28"},
    {"ALLOW", "1.2.3.4"}};

    cout << isAllowed(ip, rules) << endl;

    ip = "10.5.12.10";
    cout << isAllowed(ip, rules) << endl;

    ip = "1.2.3.4";
    cout << isAllowed(ip, rules) << endl;

    ip = "10.5.12.15";
    cout << isAllowed(ip, rules) << endl;


}

#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_set>
#include <string>
#include <unordered_map>
using namespace std;

vector<string> split(const string &s, char delimiter){
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while(getline(tokenStream, token, delimiter)){
        tokens.push_back(token);
    }
    return tokens;
}

vector<string> readInput(){
    vector<string> lines;
    string line;
    while(getline(cin, line)){
        if (line.empty()) break;
        lines.push_back(line);
    }
    return lines;
}

int main(){
    #ifdef LOCAL_TESTING
       freopen("../input.txt", "r", stdin);
       freopen("../output.txt", "w", stdout);
    #endif

    string line;
    string nonfraudline;
    while(getline(cin, line)) {
        if (line.empty()) break;
        nonfraudline = line;
    }
    unordered_set<string> nonfraud;
    for (auto &ostr : split(nonfraudline, ',')){
        string str = ostr.substr(1, ostr.size() - 2);
        nonfraud.insert(str);
    }

    string fraudline;
    while(getline(cin, line)){
        if (line.empty()) break;
        fraudline = line;
    }
    unordered_set<string> fraud;
    for (auto &ostr : split(fraudline, ',')){
        string str = ostr.substr(1, ostr.size() - 2);
        fraud.insert(str);
    }

    unordered_map<string, double> mccThreshold;
    vector<string> lines = readInput();
    for (string &line : lines){
        vector<string> mcc = split(line, ',');
        mccThreshold[mcc[0]] = stod(mcc[1]);
    }

    unordered_map<string, string> merchantMcc;
    vector<string> merchantlines = readInput();
    for (string &line : merchantlines){
        vector<string> merchant = split(line, ',');
        merchantMcc[merchant[0]] = merchant[1];
    }

    string transactionsline;
    while(getline(cin, line)){
        if (line.empty()) break;
        transactionsline = line;
    }
    int minTransactions = stoi(transactionsline);

    string chargesline;

    unordered_set<string> disputes;
    vector<vector<string>> allCharges;
    while(getline(cin, chargesline)){
        vector<string> charges = split(chargesline, ',');
        if (charges.size() == 2){
            disputes.insert(charges[1]);
            continue;
        }
        allCharges.push_back({charges[1], charges[2], charges[4]});
    }

    unordered_map<string, int> merchantFraudCount;
    unordered_map<string, int> merchantCount;

    for (auto &charges : allCharges){
        string id = charges[0];
        string merchant = charges[1];
        string charge = charges[2];
        // cout << id << " " << merchant << " " << charge << endl;
        merchantCount[merchant]++;
        if (fraud.find(charge) != fraud.end() && disputes.find(id) == disputes.end()){
            merchantFraudCount[merchant]++;
        }
    }

    vector<string> fraudMerchants;
    for (auto &merchant : merchantCount){
        string mcc = merchantMcc[merchant.first];
        if (merchant.second >= minTransactions){
            double ratio = (double)merchantFraudCount[merchant.first] / merchant.second;
            cout << merchant.first << " " << merchantFraudCount[merchant.first] << " " << merchant.second << " " << ratio << " " << mccThreshold[mcc] << endl;
            // if (ratio >= mccThreshold[mcc]){
            if (merchantFraudCount[merchant.first] >= mccThreshold[mcc]){
                fraudMerchants.push_back(merchant.first);
            }
        }
    }

    sort(fraudMerchants.begin(), fraudMerchants.end());
    for (int i = 0; i < fraudMerchants.size(); ++i){
        if (i != 0) cout << ',';
        cout << fraudMerchants[i];
    }
    return 0;
}

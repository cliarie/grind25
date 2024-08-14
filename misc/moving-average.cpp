#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <iomanip>

using namespace std;

struct Trade {
    double value;
    int quantity;
    int sequenceNumber;
};

struct TradeInfo {
    double totalValue;
    int totalQuantity;
    int lastSequenceNumber;
    double weightedMovingAverage;

    TradeInfo() : totalValue(0.0), totalQuantity(0), lastSequenceNumber(0), weightedMovingAverage(0.0) {}
};

void printKeyAndWMA(const string& key, double weightedMovingAverage) {
    cout << key << ": " << fixed << setprecision(2) << weightedMovingAverage << endl;
}

int main() {
    string input;
    getline(cin, input);

    unordered_map<string, TradeInfo> tradeMap;
    stringstream ss(input);
    string tradeData;

    while (getline(ss, tradeData, ';')) {
        stringstream tradeStream(tradeData);
        string key, valueStr, quantityStr, seqNumStr;
        getline(tradeStream, key, ',');
        getline(tradeStream, valueStr, ',');
        getline(tradeStream, quantityStr, ',');
        getline(tradeStream, seqNumStr, ',');

        double value = stod(valueStr);
        int quantity = stoi(quantityStr);
        int sequenceNumber = stoi(seqNumStr);

        Trade trade = {value, quantity, sequenceNumber};

        if (tradeMap.find(key) == tradeMap.end()) {
            tradeMap[key] = TradeInfo();
        }

        TradeInfo& tradeInfo = tradeMap[key];

        if (trade.sequenceNumber > tradeInfo.lastSequenceNumber) {
            tradeInfo.totalValue = (tradeInfo.weightedMovingAverage * tradeInfo.totalQuantity) + (trade.value * trade.quantity);
            tradeInfo.totalQuantity += trade.quantity;
            tradeInfo.weightedMovingAverage = tradeInfo.totalValue / tradeInfo.totalQuantity;
            tradeInfo.lastSequenceNumber = trade.sequenceNumber;

            printKeyAndWMA(key, tradeInfo.weightedMovingAverage);
        }
    }

    return 0;
}

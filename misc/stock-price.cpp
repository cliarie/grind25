#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class StockPrice {
private:
    int S;
    vector<pair<int, int>> dividends;
    map<int, int> cumulative_dividends;

public:
    StockPrice(int initialPrice, const vector<pair<int, int>>& initialDividends) : S(initialPrice) {
        dividends = initialDividends;
        recomputeCumulativeDividends();
    }

    void recomputeCumulativeDividends() {
        cumulative_dividends.clear();
        for (const auto& div : dividends) {
            int amount = div.first;
            int day = div.second;
            cumulative_dividends[day] += amount;
        }

        int currentCumulative = 0;
        for (auto it = cumulative_dividends.begin(); it != cumulative_dividends.end(); ++it) {
            currentCumulative += it->second;
            it->second = currentCumulative;
        }
    }

    void dividendUpdate(int i, int A, int D) {
        if (i < 1 || i > dividends.size()) {
            return;
        }
        dividends[i - 1] = make_pair(A, D);
        recomputeCumulativeDividends();
    }

    int price(int F) {
        auto it = cumulative_dividends.lower_bound(F);
        if (it == cumulative_dividends.end() || it->first > F) {
            if (it != cumulative_dividends.begin()) {
                --it;
            } else {
                return S;
            }
        }
        return S - it->second;
    }
};

int main() {
    int S = 1000;
    vector<pair<int, int>> initialDividends = {{100, 10}, {50, 100}};
    StockPrice stock(S, initialDividends);

    cout << stock.price(9) << endl;  // Output: 1000
    cout << stock.price(10) << endl;  // Output: 900
    cout << stock.price(99) << endl;  // Output: 900
    cout << stock.price(100) << endl;  // Output: 850

    stock.dividendUpdate(1, 200, 20);
    cout << stock.price(9) << endl;  // Output: 1000
    cout << stock.price(10) << endl;  // Output: 1000
    cout << stock.price(20) << endl;  // Output: 800
    cout << stock.price(100) << endl;  // Output: 750

    return 0;
}

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <map>

using namespace std;

class BeverageStandManager {
private:
    int number_of_stores;
    int number_of_orders;
    int number_of_different_beverages;
    int number_of_beverages;

    unordered_map<string, int> number_of_each_beverage;
    unordered_map<int, unordered_map<string, int>> store_orders;
    unordered_set<int> active_stores;

    int limit_number_of_stores;
    unordered_map<string, int> limit_per_beverage_total;

public:
    BeverageStandManager() {
        number_of_stores = 0;
        number_of_orders = 0;
        number_of_different_beverages = 0;
        number_of_beverages = 0;

        limit_number_of_stores = 0;
    }

    void UpdateLimit(int numberOfStores, const unordered_map<string, int>& perBeverageTotal) {
        limit_number_of_stores = numberOfStores;
        limit_per_beverage_total = perBeverageTotal;

        bool limitsExceeded = false;

        if (number_of_stores > limit_number_of_stores) {
            limitsExceeded = true;
        }

        for (const auto& beverage : number_of_each_beverage) {
            if (limit_per_beverage_total.find(beverage.first) != limit_per_beverage_total.end() &&
                beverage.second > limit_per_beverage_total[beverage.first]) {
                limitsExceeded = true;
                break;
            }
        }

        if (limitsExceeded) {
            CloseAllStores();
        }
    }

    void ProcessOrder(int uniqueId, int storeId, const string& beverageName, int quantity) {
        if (quantity > 0 && (
            (number_of_stores + (active_stores.find(storeId) == active_stores.end() ? 1 : 0) > limit_number_of_stores) ||
            (limit_per_beverage_total.find(beverageName) != limit_per_beverage_total.end() &&
            number_of_each_beverage[beverageName] + quantity > limit_per_beverage_total[beverageName]))) {
            cout << "reject_order: " << uniqueId << endl;
            return;
        }

        if (store_orders[storeId].find(beverageName) != store_orders[storeId].end()) {
            int old_quantity = store_orders[storeId][beverageName];
            if (old_quantity > 0) {
                number_of_orders--;
                number_of_each_beverage[beverageName] -= old_quantity;
                number_of_beverages -= old_quantity;
                if (number_of_each_beverage[beverageName] == 0) {
                    number_of_different_beverages--;
                    number_of_each_beverage.erase(beverageName);
                }
            }
        }

        if (quantity > 0) {
            store_orders[storeId][beverageName] = quantity;
            number_of_orders++;
            number_of_each_beverage[beverageName] += quantity;
            if (number_of_each_beverage[beverageName] == quantity) {
                number_of_different_beverages++;
            }
            number_of_beverages += quantity;
            active_stores.insert(storeId);
        } else {
            store_orders[storeId].erase(beverageName);
        }

        if (store_orders[storeId].empty()) {
            active_stores.erase(storeId);
        }

        number_of_stores = active_stores.size();
    }

    void CloseStore(int storeId) {
        if (store_orders.find(storeId) != store_orders.end()) {
            for (const auto& order : store_orders[storeId]) {
                number_of_each_beverage[order.first] -= order.second;
                number_of_beverages -= order.second;
                if (number_of_each_beverage[order.first] == 0) {
                    number_of_different_beverages--;
                    number_of_each_beverage.erase(order.first);
                }
                number_of_orders--;
            }
            store_orders.erase(storeId);
            active_stores.erase(storeId);
            number_of_stores = active_stores.size();
        }
    }

    void CloseAllStores() {
        number_of_stores = 0;
        number_of_orders = 0;
        number_of_different_beverages = 0;
        number_of_beverages = 0;
        number_of_each_beverage.clear();
        store_orders.clear();
        active_stores.clear();
    }

    void PrintState() {
        cout << "number_of_stores: " << number_of_stores << ", "
             << "number_of_orders: " << number_of_orders << ", "
             << "number_of_different_beverages: " << number_of_different_beverages << ", "
             << "number_of_beverages: " << number_of_beverages << endl;
    }
};

int main() {
    BeverageStandManager manager;
    manager.UpdateLimit(5, {{"lemonade", 50}, {"iced tea", 30}});
    manager.ProcessOrder(1, 1, "lemonade", 10);
    manager.ProcessOrder(2, 2, "iced tea", 20);
    manager.ProcessOrder(3, 1, "lemonade", 5);  // This should move scout 1 to the back of the line for lemonade
    manager.PrintState();

    manager.ProcessOrder(4, 1, "lemonade", 0);  // Scout 1 no longer wants lemonade
    manager.PrintState();

    manager.CloseStore(2);  // Close scout 2's store
    manager.PrintState();

    manager.UpdateLimit(2, {{"lemonade", 10}, {"iced tea", 10}});  // This should close all stores as the new limits are exceeded
    manager.PrintState();

    return 0;
}

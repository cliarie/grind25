#include <iostream>
#include <unordered_map>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

class Customer {
public:
    int id;
    int lineNumber;
    int numItems;

    Customer(int id, int lineNumber, int numItems)
        : id(id), lineNumber(lineNumber), numItems(numItems) {}
};

class Supermarket {
private:
    unordered_map<int, deque<Customer>> lines;
    unordered_map<int, Customer> customers;

public:
    void OnCustomerEnter(int customerId, int lineNumber, int numItems) {
        Customer newCustomer(customerId, lineNumber, numItems);
        lines[lineNumber].push_back(newCustomer);
        customers[customerId] = newCustomer;
    }

    void OnBasketChange(int customerId, int newNumItems) {
        Customer &customer = customers[customerId];
        if (newNumItems == 0) {
            // Customer leaves the store
            OnCustomerExit(customerId);
        } else if (newNumItems > customer.numItems) {
            // Customer goes to the back of the line
            customer.numItems = newNumItems;
            deque<Customer> &line = lines[customer.lineNumber];
            auto it = find_if(line.begin(), line.end(), [customerId](const Customer &c) {
                return c.id == customerId;
            });
            if (it != line.end()) {
                line.erase(it);
                line.push_back(customer);
            }
        } else {
            // Customer keeps their position
            customer.numItems = newNumItems;
        }
    }

    void OnLineService(int lineNumber, int numProcessedItems) {
        deque<Customer> &line = lines[lineNumber];
        while (numProcessedItems > 0 && !line.empty()) {
            Customer &customer = line.front();
            if (customer.numItems <= numProcessedItems) {
                numProcessedItems -= customer.numItems;
                line.pop_front();
                OnCustomerExit(customer.id);
            } else {
                customer.numItems -= numProcessedItems;
                numProcessedItems = 0;
            }
        }
    }

    void OnLinesService() {
        for (auto &linePair : lines) {
            int lineNumber = linePair.first;
            OnLineService(lineNumber, 1);
        }
    }

    void OnCustomerExit(int customerId) {
        cout << "Customer " << customerId << " has left the store." << endl;
        customers.erase(customerId);
    }
};

int main() {
    Supermarket supermarket;
    supermarket.OnCustomerEnter(1, 0, 5);
    supermarket.OnCustomerEnter(2, 0, 3);
    supermarket.OnCustomerEnter(3, 1, 4);

    supermarket.OnBasketChange(1, 7);
    supermarket.OnLineService(0, 5);
    supermarket.OnLinesService();

    return 0;
}

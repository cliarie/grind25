#include <iostream>

using namespace std;

class LemonadeStand{
    private:
        int stores, orders, differentbev, bev;
        int limit, perBevTotal;
        unordered_map<string, int> storetobevs;
    public:
        LemonadeStand(){
            stores = 0, orders = 0, differentbev = 0, bev = 0;
        }
        void UpdateLimit(int numStores, int perBevTotal){
            limit = numStores;
            this->perBevTotal = perBevTotal;
        }
        void ProcessOrder(int uniqueId, int storeId, string bevName, int quantity){

        }
        void CloseStore(int storeId){

        }

        void PrintState(){
            cout << "Stores: " << stores << endl;
            cout << "Orders: " << orders << endl;
            cout << "Different Bev: " << differentbev << endl;
            cout << "Bev: " << bev << endl;
        }

};

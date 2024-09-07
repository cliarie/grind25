#include <iostream>
#define ll long long
using namespace std;

int main(){
    string input;
    ll l = 1, r = 1e18;
    int times = 60;
    while(times--) {
        ll mid = (l + r + 1) / 2;
        cout << mid << endl;
        cin >> input;
        if (input == "CORRECT"){
            break;
        }
        if (input == "HIGHER"){
            l = mid;
        }
        else if (input == "LOWER") r = mid - 1;
    }
}

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    double a; cin >> a;
    double first = 100.0/a;
    double second = 100.0/(100.0-a);

    cout << fixed << setprecision(10);
    cout << first << endl;
    cout << second << endl;
}

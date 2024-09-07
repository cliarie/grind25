#include <iomanip>
#include <iostream>
using namespace std;

int main(){
    #ifdef LOCAL_TESTING
       freopen("../input.txt", "r", stdin);
       freopen("../output.txt", "w", stdout);
    #endif

    double dl, dw, g, l;
    cin >> dl >> dw >> g >> l;
    double w = 100 - l;
    double pnog = (100-g)/100.0;
    double prizes = 1/(1-pnog);
    double matches = 0;
    double p = 0;

    while (p < 100){
        matches += (w / 100.0);
        p += dw;
        if (p >= 100) break;

        matches += (l / 100.0);
        p += dl;
        if (p >= 100) break;
    }
    matches *= prizes;

    cout << fixed << setprecision(10) << matches << endl;
}

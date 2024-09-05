#include <iostream>
using namespace std;

int main(){
    #ifdef LOCAL_TESTING
       freopen("../input.txt", "r", stdin);
       freopen("../output.txt", "w", stdout);
    #endif
    int t; cin >> t;
    for (int i = 0; i < t; ++i){
        int n; cin >> n;
        int pos = 0;
        int m;
        while(n>>pos){
            if (1 & (n>>pos)){
                m = n &(1<<pos);
                pos++;
                break;
            }
            pos++;
        }
        if (n == 1) cout << 3 << endl;
        else if (n >> pos) cout << m << endl;
        else cout << m + 1 << endl;
    }
}

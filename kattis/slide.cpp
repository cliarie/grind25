#include <iostream>
#include <vector>
using namespace std;

int main(){
    #ifdef LOCAL_TESTING
       freopen("../input.txt", "r", stdin);
       freopen("../output.txt", "w", stdout);
    #endif
    int n, c; cin >> n >> c;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    vector<int> ps(n + 1, 0);
    int s = 0, e = -1;  // start and end pointers for sliding window
    int sum = 0;  // current sum of the window

    while (s < n) {
        if (s <= e){
            ++ps[s];
            --ps[e + 1];
        }
        if (e + 1 >= n){
            sum -= arr[s];
            ++s;
        }
        else if (sum + arr[e + 1] > c){
            sum -= arr[s];
            ++s;
        }
        else{
            e++;
            sum += arr[e];
        }
    }

    for (int i = 1; i < n; ++i){
        ps[i] += ps[i - 1];
    }
    for (int i = 0; i < n; ++i){
        cout << ps[i] << endl;
    }
}

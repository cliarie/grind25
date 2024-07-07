#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    multiset<int> window;
    for (int i = 0; i < k; ++i) window.insert(arr[i]);
    auto it = window.begin();
    if (k != 1 && k != 2) advance(it, (k-1)/2);
    for (int i = k; i < n; ++i){
        // for (auto i : window ) cout << i << " ";
        // cout << "ARR" << arr[i - k] <<endl;
        cout << *it << endl;
        // cout <<"Hd" << arr[i] << *it << arr[i-k];
        if ((arr[i - k] > *it && arr[i] > *it) || (arr[i - k] < *it && arr[i] < *it )) {
            window.insert(arr[i]);
            window.erase(window.find(arr[i - k]));
        }
        else if (arr[i - k] == *it && arr[i] == *it || arr[i] == *it && arr[i - k] < *it){
            window.insert(arr[i]);
            it++;
            window.erase(prev(it));
        }
        else{
            if (arr[i] < *it) {
                window.insert(arr[i]);
                it--;
                if (*next(it) == arr[i - k]) window.erase(next(it));
                else window.erase(window.find(arr[i - k]));
            }
            else if (arr[i] > *it) {
                window.insert(arr[i]);
                it++;
                if (*prev(it) == arr[i - k]) window.erase(prev(it));
                else window.erase(window.find(arr[i - k]));
            }
            else {
                window.insert(arr[i]);
                window.erase(window.find(arr[i - k]));
            }
        }
    }
    // for (auto i : window ) cout << i << " ";
    // cout << "ARR" << arr[n - k] <<endl;
    cout << *it << endl;
}

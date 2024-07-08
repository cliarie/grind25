#include <iostream>
#include <vector>
#include <set>
#define ll long long
using namespace std;

/*
similar to stick lengths + sliding window median:
- make all values in window equal to the median
- median using two multisets, k/2 smaller elements, and k/2 larger; median is largest of first set

- cost = (median - smaller_i) + (larger_i - median)
 = median * smaller.size() - sum of elements in smaller + sum of larger - median * larger.size()
*/
int main(){
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    multiset<int> smaller;
    multiset<int> larger;
    int ssum = 0, lsum = 0;
    for (int i = 0; i < n; ++i){
        if (smaller.size() > larger.size()) {
            larger.insert(arr[i]);
            lsum += arr[i];
        }
        else {
            smaller.insert(arr[i]);
            ssum += arr[i];
        }

        int last = *smaller.rbegin(), first = *larger.begin();
        if (*smaller.rbegin() > *larger.begin()){
            smaller.erase(--smaller.end());
            larger.erase(larger.begin());
            smaller.insert(first);
            larger.insert(last);
            ssum += first - last;
            lsum += last - first;
        }

        int med = *smaller.rbegin();
        if (i >= k - 1){
            // cout << "MED " << med <<endl;
            // for (auto i : smaller) cout << i << " ";
            // cout << endl;
            // for (auto i : larger) cout << i << " ";
            // cout << endl;
            // cout << "DEL " << arr[i - k + 1] << endl;
            int cost = med * smaller.size() - med * larger.size() - ssum + lsum;
            cout << cost << endl;
            if (smaller.find(arr[i - k + 1]) != smaller.end()) {
                smaller.erase(smaller.find(arr[i - k + 1]));
                ssum -= arr[i - k + 1];
            }
            else {
                larger.erase(larger.find(arr[i - k + 1]));
                lsum -= arr[i - k + 1];
            }
        }
    }
}

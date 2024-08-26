#include <vector>
#include <iostream>
#define pii pair<int, int>
using namespace std;

int countsegments(vector<int> &capacity){
    // cap[l] == cap[r] == sum[l + 1:r - 1];
    unordered_map<int, int> pf;
    unordered_map<int, int> ele;
    int n = capacity.size(), count = 0;
    vector<int> prefix(n + 1, 0);
    pf[0] = 0;
    for (int i = 1; i < n; ++i){
        prefix[i] = prefix[i - 1] + capacity[i - 1];
        pf[prefix[i]] = i;
        ele[capacity[i]] = i;
        cout << "PRE" << prefix[i] << endl;
        if (prefix[i] >= 2 * capacity[i]){
            int f = prefix[i] - 2 * capacity[i];
            cout << f << endl;
            if (pf.find(f) != pf.end()){
                cout << pf[f] << " " << capacity[i] << endl;
                if (capacity[pf[f]] == capacity[i]) {
                    count++;
                    cout << "Y" << endl;
                }
            }
        }
    }

    return count;
}

int main(){
    vector<int> cap = {1, 3, 1, 2, 3, 9};
    cout << countsegments(cap) << endl;
}

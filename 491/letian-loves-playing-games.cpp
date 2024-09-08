#include <iostream>
using namespace std;

int query(int val){
    cout << "? " << val << endl;
    cout.flush();
    int res;
    cin >> res;
    return res;
}

int main(){
    int n;
    cin >> n;
    int l = 1, r = n;
    while(l < r){
        int mid = (l + r) / 2;
        int leftn = INT_MAX, rightn = INT_MAX;
        int m = query(mid);
        if (mid > 1) leftn = query(mid - 1);
        if (mid < n) rightn = query(mid + 1);
        if (m < leftn && m < rightn){
            cout << "! " << mid << endl;
            return 0;
        }
        else if (m > leftn) r = mid - 1;
        else l = mid + 1;
    }
    cout << "! " << l << endl;
}

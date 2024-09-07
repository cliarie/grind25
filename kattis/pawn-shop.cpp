#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    #ifdef LOCAL_TESTING
       freopen("../input.txt", "r", stdin);
       freopen("../output.txt", "w", stdout);
    #endif
    int n; cin >> n;
    vector<int> A(n), B(n);

    for (auto &i : A) cin >> i;
    for (auto &i : B) cin >> i;

    unordered_map<int, int> nums;
    int non_zeros = 0;
    for (int i = 0; i < n; ++i){
        nums[A[i]]++;
        nums[B[i]]--;
        int a = nums[A[i]];
        int b = nums[B[i]];

        if (A[i] != B[i]){
            if (a == 1) ++non_zeros;
            else if (a == 0) --non_zeros;
            if (b == -1) ++non_zeros;
            else if (b == 0) --non_zeros;
        }
        cout << B[i] << " ";
        if (non_zeros == 0 && i + 1 != n) cout << "# ";
    }
    cout << endl;
}

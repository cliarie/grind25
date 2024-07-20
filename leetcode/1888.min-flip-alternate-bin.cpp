#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        vector<int> arr(2*n);
        for (int i = 0; i < 2 * n; ++i){
            arr[i] = s[i%n] - '0';
        }

        int ans0 = 0, ans1 = 0;
        for (int i = 0; i < n; ++i){
            ans1 += arr[i] == i%2;
        }
        ans0 = n - ans1;
        int rmin = min(ans0, ans1);
        for (int i = 0; i < n; ++i){
            if (arr[i] == i % 2) ans1--;
            else ans0--;
            if (arr[i + n] == (i + n) % 2) ans1++;
            else ans0++;
            rmin = min(min(ans0, ans1), rmin);
        }
        return rmin;
    }
};

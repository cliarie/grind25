#include <string>
using namespace std;
const int MOD = 1e9 + 7;

class Solution {
public:
    int countHomogenous(string s) {
        int ans = 0, cur = 0;

        for (int i = 0; i < s.size(); ++i){
            if (i == 0 || s[i] == s[i - 1]) cur++;
            else cur = 1;
            ans = (ans + cur) % MOD;
        }
        return ans;
    }
};

#include <string>
using namespace std;
class Solution {
public:
    int countLetters(string s) {
        int l = 0, r = 0, count = 0;
        while(r < s.size()){
            r++;
            if (s[r] != s[l]){
                int n = r - l;
                count += n*(n+1)/2;
                l = r;
            }
        }
        return count;
    }
};

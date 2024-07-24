#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
       vector<int> freqp(26, 0), freqs(26, 0), ans;

        int m = p.length(), n = s.length();
       for (int i = 0; i < m; ++i){
        freqp[p[i] - 'a']++;
       }
       for (int i = 0; i < n; ++i){
        freqs[s[i]-'a']++;
        if (i >= m){ // sli
            freqs[s[i-m]-'a']--;
        }
        if (freqp == freqs) ans.push_back(i - m + 1);
       } 
       return ans;
    }
};


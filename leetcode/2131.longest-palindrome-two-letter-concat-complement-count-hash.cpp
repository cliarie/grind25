#include <string>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        //sort(words.begin(), words.end());
        unordered_map<string, int> m;
        int pairs = 0, singles = 0;
        for (auto &s : words){
            string t = s;
            reverse(t.begin(), t.end());
            //cout << s << m[s] << " " << t << m[t] << endl;
            if (m[s] > 0) {
                pairs+=2;
                m[s]--;
                if (s == t) singles--;
                continue;
            }
            m[t]++;
            if (s == t) singles++;
        }
        return (singles) ? (pairs + 1) * 2 : pairs * 2;
    }
};

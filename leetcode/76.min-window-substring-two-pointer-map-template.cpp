#include <vector>
#include <map>
#include <string>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> freq;
        for (auto &c : t) freq[c]++;

        int begin = 0, end = 0;
        int counter = t.length(); // when 0 then valid
        int d = s.length() + 1; // length of ans to substr later
        int start = 0;

        while(end < s.length()){
            if (freq[s[end]] > 0) counter--;
            freq[s[end]]--;
            end++;
            while(counter == 0){
                if (end - begin < d){
                    d = end - begin;
                    start = begin;
                }
                if (freq[s[begin]] >= 0) counter++; // part of t
                freq[s[begin]]++;
                begin++;
            }
        }
        // cout << start << " " << d << endl;
        return (d == s.length() + 1) ? "" : s.substr(start, d);
    }
};

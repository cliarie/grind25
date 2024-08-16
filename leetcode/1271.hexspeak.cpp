#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    string toHexspeak(string num) {
        auto n = stoll(num);
        stringstream ss;
        ss << hex << uppercase << n;
        string s(ss.str());
        for (auto i = 0; i < s.size(); ++i){
            if (s[i] == '0') s[i] = 'O';
            else if (s[i] == '1') s[i] = 'I';
            else if (s[i] > '1' && s[i] <= '9')return "ERROR";
        }
        return s;
    }
};

class Solution {
public:
    bool doesAliceWin(string s) {
        int vc = 0;
        for (auto c : s) if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') vc++;
        if (!vc) return false;
        if (vc%2) return true;
        // if vowels even, alice should take all but one, auto win 
        return true;
    }
};

class Solution {
public:
    int countSubstrings(string s) {
       // fuck manachers
       int count = 0;
       for (int i = 0; i < s.length(); ++i){
            int l = i, r = i;
            while (l >=0 && r < s.length() && s[l] == s[r]){
                l--; r++;
                count++;
            }
       } // only 1 center
       for (int i = 0; i < s.length() - 1; ++i){
            int l = i, r = i + 1;
            while (l >=0 && r < s.length() && s[l] == s[r]){
                l--; r++;
                count++;
            }
       } // 2 centers
       return count;
    }
};

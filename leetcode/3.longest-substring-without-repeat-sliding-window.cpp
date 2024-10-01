class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> freq;
        int maxl = 0;
        int start = 0, end = 0;
        while(end < s.length()){
            freq[s[end]]++;

            while(freq[s[end]] > 1){
                freq[s[start]]--;
                start++;
            }
            cout << start << " " << end << endl;
            maxl = max(maxl, end - start + 1);
            end++;
        }
        return maxl;
    }
};

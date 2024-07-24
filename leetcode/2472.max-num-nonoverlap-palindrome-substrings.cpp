class Solution {
public:
    int maxPalindromes(string s, int k) {
       // find shortest palindromes with at least k and record their start / end
       // then dp like scheduling problem
       // dp[i] is ans for s[0...i]
        int n = s.length();
        vector<pair<int, int>> pali;
        for (int i = 0; i < n; ++i){
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]){
                if (r - l + 1 >= k) {
                    pali.push_back({r, l});
                    break;
                }
                l--; r++;
            }
        }        
        for (int i = 1; i < n; ++i){
            int l = i - 1, r = i;
            while (l >= 0 && r < n && s[l] == s[r]){
                if (r - l + 1 >= k) {
                    pali.push_back({r, l});
                    break;
                }
                l--; r++;
            }
        }
        sort(pali.begin(), pali.end());

        for (auto i : pali) cout << i.first << i.second << endl;

        int m = pali.size();
        if (m == 0) return 0;
        vector<int> dp(m, 0);
        for (int i = 0; i < m; ++i){
            // the first end before cur start;
            pair<int, int> p = {pali[i].second, 0};
            auto geit = lower_bound(pali.begin(), pali.begin() + i, p);
            if (geit == pali.begin() || geit == pali.end()) {
                dp[i] = 1;
                continue;
            }
            int idx = prev(geit) - pali.begin();
            cout << i << "d " << idx << endl;
            dp[i] = max(dp[i], dp[idx] + 1);
        }

        for (int i = 0; i < m; ++i)cout << i << " " << dp[i] << endl;

        return dp[m-1];

    }
};


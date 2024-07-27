class Solution {
public:
    bool ispali(string &s){
        int l = 0, r = s.length() - 1;
        while (r > l){
            if (s[l] != s[r]) return false;
            r--; l++;
        }
        return true;
    }

    void dfs(string &s, string &s1, string &s2, int i, int &maxprod){
        // choose s[i] s1, choose s[i] s2, don't choose s[i]
        //cout << i << endl;
        if (i > s.length()) return;
        //cout << s1 << " " << s2 << endl;
        int prod = s1.length() * s2.length();
        if (ispali(s1) && ispali(s2)) maxprod = max(prod, maxprod);
        s1.push_back(s[i]);
        dfs(s, s1, s2, i + 1, maxprod);
        s1.pop_back();

        s2.push_back(s[i]);
        dfs(s, s1, s2, i + 1, maxprod);
        s2.pop_back();

        dfs(s, s1, s2, i + 1, maxprod);

    }
    int maxProduct(string s) {
        string s1 = "", s2 = "";
        int maxprod = 0, i = 0;
        dfs(s, s1, s2, i, maxprod);
        return maxprod;
    }
};

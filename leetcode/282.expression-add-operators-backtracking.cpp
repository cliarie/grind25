#define ll long long

class Solution {
public:
    vector<string> ans;
    string num;
    int target;

    void dfs(int idx, string exp, ll cur, ll prev){
        if (idx == num.length()){
            if (cur == target) {
                if (exp == "1+2+3-4*5-6-7+8*9") cout << "hi" << endl;
                ans.push_back(exp);
            }
            return;
        }

        ll nn = 0; string ns;
        for (int i = idx; i < num.length(); ++i){
            // if (exp == "1*2*3*4*5-6-78+9") cout << "hi" << endl;
            if (i > idx && num[i - 1] == '0') return;
            nn = nn * 10 + (num[i] - '0');
            if (exp == "1*2*3*4*5-6-78") cout << cur << " " << prev << " " << nn << " " << ((cur-prev) * nn) + prev << endl;;
            ns += num[i];
            if (idx == 0) {
                dfs(i + 1, exp + ns, nn, 0);
                continue;
            }

            dfs(i + 1, exp + "+" + ns, cur + nn, cur);
            dfs(i + 1, exp + "-" + ns, cur - nn, cur);
            dfs(i + 1, exp + "*" + ns, ((cur-prev) * nn) + prev, prev * nn); // precedence! undo prev op and first do mult
        }
    }
    vector<string> addOperators(string num, int target) {
        this->num = num;
        this->target = target;
        dfs(0, "", 0, 0);
        return ans;
    }
};

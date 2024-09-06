class Solution {
public:
    int calculate(string s) {
        stack<int> st;

        int num = 0;
        int res = 0;
        int prevsign = 1;
        for (int i = 0; i < s.length(); ++i){
            if (isdigit(s[i])){
                num = 10 * num + (s[i] - '0');
            }
            else if (s[i] == '+'){
                res += prevsign * num;
                prevsign = 1;
                num = 0;
            }
            else if (s[i] == '-'){
                res += prevsign * num;
                prevsign = -1;
                num = 0;
            }
            else if (s[i] == '('){
                st.push(res);
                st.push(prevsign);

                prevsign = 1;
                res = 0;
            }
            else if (s[i] == ')'){
                res += prevsign * num;
                int keptsign = st.top();
                st.pop();
                res *= keptsign;
                int keptnum = st.top();
                st.pop();
                res += keptnum;

                num = 0;
                prevsign = 1;
            }
        }
        return res += prevsign * num;
    }
};

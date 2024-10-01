class Solution {
public:
    bool isValid(string s) {
        unordered_set<char> open = {'(', '{', '['};
        stack<char> parens;
        for (auto c : s){
            if (open.find(c) != open.end()){
                parens.push(c);
            } else{
                if (parens.empty()) return false;
                if (parens.top() == '(' && c == ')' ||
                    parens.top() == '{' && c == '}' ||
                    parens.top() == '[' && c == ']' ){
                        parens.pop();
                    }
                else return false;
            }
        }
        return parens.empty();
    }
};

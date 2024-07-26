class Solution {
public:
    string removeKdigits(string num, int k) {
        deque<int> dq;
        int count = 0;
        for (int i = 0; i < num.size(); ++i){
            while (dq.size() > 0 && dq.back() > num[i] && count != k) {
                dq.pop_back();
                count++;
            }
            dq.push_back(num[i]);
        }

        while(count != k){
            dq.pop_back();
            count++;
        }
        
        string tor; bool start = false;
        while (!dq.empty()){
            if (dq.front() != '0' || tor != "") tor += dq.front();
            dq.pop_front();
        }
        // for (auto c : num){
        //     if (c == dq.front()){
        //         dq.pop_front();
        //     }
        //     else if (c == '0' && !start) continue;
        //     else {tor += c; start = true;}
        // }
        // tor = tor.substr(0, num.size() - k);
        return (tor == "") ? "0" : tor;
    }
};

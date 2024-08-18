#include <unordered_map>
#include <stack>
using namespace std;
class FreqStack {
    // 1. max freq, 2. most recent
public:
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> mstack; // nums with that freq
    int curmax;
    FreqStack() {

    }

    void push(int val) {
        freq[val]++;
        if (freq[val] > curmax){
            curmax = freq[val];
        }
        mstack[freq[val]].push(val);
    }

    int pop() {
        int ans = mstack[curmax].top();
        freq[ans]--;
        mstack[curmax].pop();
        if (mstack[curmax].empty()) curmax--;
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */

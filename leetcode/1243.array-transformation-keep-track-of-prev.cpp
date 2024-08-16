#include <vector>
using namespace std;
class Solution {
public:
    vector<int> transformArray(vector<int>& arr) {
        bool change = false;
        while(true){
            change = false;
            int prev = arr[0], cur = arr[1], next = arr[2];
            for (int i = 1; i < arr.size() - 1; ++i){
                if (prev > cur && next > cur) {
                    change = true;
                    arr[i]++;
                }
                if (prev < cur && next < cur) {
                    change = true;
                    arr[i]--;
                }
                prev = cur;
                cur = next;
                next = arr[i + 2];
            }
            if (!change) break;
        }
        return arr;
    }
};

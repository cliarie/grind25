#include <vector>
using namespace std;
class Solution {
public:
    int maxNumberOfApples(vector<int>& weight) {
        sort(weight.begin(), weight.end());
        int total = 0, n = 0;
        for (int i = 0; i < weight.size(); ++i){
            total += weight[i];
            if (total > 5000) break;
            n++;
        }
        return n;
    }
};

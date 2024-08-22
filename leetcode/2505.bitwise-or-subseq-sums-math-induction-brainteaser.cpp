#include <vector>
using namespace std;
class Solution {
public:
    long long subsequenceSumOr(vector<int>& nums) {
        // don't need to find all subseq sums
        // bit is one if bit in element in array or if bit in sum of elements in array
        // subseq:, x, y, z, x + y, x + y + z
        // suppose all subseq 0 at nth bit, can x + z / y + z be one at nth bit?
        // x + y < 2^(n-1), z < 2^(n-1)
        // x + y + z < 2^(n), but x + y + z < 2^(n-1)
        // then y + z and x + z < 2^(n-1), so also 0 at nth bit
        long long ans = 0, ps = 0;
        for (auto &n : nums){
            ps += n;
            ans = ans | n;
            ans = ans | (ps);
        }
        return ans;
    }
};

#include <vector>
using namespace std;
class Solution {
public:
    bool check(vector<int>& v, long long n, long long x, long long y){
        long long t = 0;
        for (int i = 0; i < v.size(); ++i){
            if (t > n) return false;
            long long diff = v[i] - n * y;
            if (n == 2) cout << diff << endl;
            if (diff > 0) t += (diff%(x-y)==0) ? diff / (x-y) : (diff / (x-y)) + 1;
        }
        return t <= n;
    }
    int minOperations(vector<int>& v, int x, int y) {
        long long n = v.size();
        long long l = 0, r = 1e9 + 1;
        while (r > l){
            int mid = (l + r) / 2;
            if (check(v, mid, x, y)) r = mid;
            else l = mid + 1;
        } 
        return l;
    }
};

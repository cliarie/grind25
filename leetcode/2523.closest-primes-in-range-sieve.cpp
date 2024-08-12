#include <vector>
using namespace std;
class Solution {
public:
    vector<int> sieve(int l, int r){
        vector<bool> prime(r + 1, 1);
        for (int i = 2; i * i <= r; ++i){
            if (prime[i]){
                for (int j = i*i; j <= r; j += i){
                    prime[j] = false;
                }
            }
        }
        vector<int> ans;
        for (int i = max(l, 2); i <= r; ++i){
            if (prime[i]) ans.push_back(i);
        }
        return ans;
    }

    vector<int> closestPrimes(int left, int right) {
        vector<int> primes = sieve(left, right);
        if (primes.size() <= 1) return {-1, -1};

        int a, b, m = 1e6 + 1;
        for (int i = 1; i < primes.size(); ++i){
            if (primes[i] - primes[i-1] < m){
                m = primes[i] - primes[i-1];
                a = primes[i - 1]; b = primes[i];
            }
        }
        return {a, b};
    }
};

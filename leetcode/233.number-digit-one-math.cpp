class Solution {
public:
    int countDigitOne(int n) {
        // digit dp
        // ones: n/10 + n%10 >= 1, upper limit add 1;
        // tens: 10 * n/100 + n%100 >= 10, upper limit add 10
        // hund: 100 * n/1000 + n%1000, upper limit add 100
        // if (n != 0 && n < 10) {return 1;}
        int ans = 0;
        for (long long i = 1; i <= n; i *= 10){
            int a = n / (i*10) * i;
            int b = 0;
            if (n % (i*10) >= i){
                if (n % (i*10) >= i + i) b = i;
                else b = (n % (i*10)) - i + 1;
            }
            ans += a + b;
        }
        return ans;
    }
};

#include <iostream>
// #include <gmpxx.h>
#include <bits/stdc++.h>

using namespace std;

// Helper function to convert binary string to mpz_class (GMP's arbitrary precision type)
mpz_class binaryToInt(const string &binary) {
    mpz_class result("0", 2); // Initialize mpz_class with binary base
    mpz_set_str(result.get_mpz_t(), binary.c_str(), 2);
    return result;
}

string intToBinary(const mpz_class &n) {
    return n.get_str(2);
}

int main() {
    #ifdef LOCAL_TESTING
       freopen("../input.txt", "r", stdin);
       freopen("../output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s_bin, d_bin, m_bin;
    cin >> s_bin >> d_bin >> m_bin;

    // Convert binary strings to mpz_class (arbitrary precision integers)
    mpz_class s = binaryToInt(s_bin);
    mpz_class d = binaryToInt(d_bin);
    mpz_class m = binaryToInt(m_bin);

    mpz_class current_money = m;
    mpz_class day = 0;

    while (true) {
        if (current_money == 0) {
            cout << intToBinary(day) << endl;
            return 0;
        }

        if (current_money % 2 == 0) {
            current_money /= 2;
        } else {
            current_money = current_money / 2 + 1;
        }

        if ((day + 1) % d == 0) {
            current_money += s;
        }

        if (day > 1000000) {
            cout << "Infinite money!" << endl;
            return 0;
        }

        ++day;
    }

    return 0;
}

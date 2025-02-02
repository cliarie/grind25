/*
given n pairs of P_k, S_k
find n pairs of p_i, s_i such that p_i + p_j != P_k and s_i + s_j != S_k
n <= 2000
O(n^2) is fine
if doesn't exist output no
subarray sum
*/
#include <iostream>
#include <vector>
using namespace std;

// Maximum possible sum for p and s is 2*N
const int MAX_SUM = 4002;

// Global forbidden sum array
bool forbidden[MAX_SUM][MAX_SUM];

int main(){
    #ifdef LOCAL_TESTING
       freopen("../input.txt", "r", stdin);
       freopen("../output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    // Initialize forbidden array to false
    for(int i = 0; i < MAX_SUM; ++i){
        for(int j = 0; j < MAX_SUM; ++j){
            forbidden[i][j] = false;
        }
    }

    // Read forbidden pairs and mark them
    for(int k = 0; k < N; ++k){
        int Pk, Sk;
        cin >> Pk >> Sk;
        if(Pk < MAX_SUM && Sk < MAX_SUM){
            forbidden[Pk][Sk] = true;
        }
    }

    // List to store assigned pairs
    vector<pair<int, int>> assigned;

    // Iterate through all possible pairs
    for(int p = 1; p <= N && (int)assigned.size() < N; ++p){
        for(int s = 1; s <= N && (int)assigned.size() < N; ++s){
            // check if pair violates itself
            if(forbidden[2*p][2*s]){
                continue;
            }
            bool valid = true;
            // vceck with all previously assigned pairs
            for(auto &prev : assigned){
                int sum_p = p + prev.first;
                int sum_s = s + prev.second;
                if(sum_p < MAX_SUM && sum_s < MAX_SUM && forbidden[sum_p][sum_s]){
                    valid = false;
                    break;
                }
            }
            if(valid){
                assigned.emplace_back(p, s);
            }
        }
    }

    if(assigned.size() == N){
        cout << "YES\n";
        for(auto &p : assigned){
            cout << p.first << " " << p.second << "\n";
        }
    }
    else{
        cout << "NO\n";
    }
}

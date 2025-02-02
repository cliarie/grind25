// break n into groups of 2s and 3s
#include <iostream>
#include <vector>

using namespace std;

int main(){
    #ifdef LOCAL_TESTING
       freopen("../input.txt", "r", stdin);
       freopen("../output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> groups;
    while(n > 0){
        if(n >= 3){
            groups.push_back(3);
            n -= 3;
        }else if (n == 2){
            groups.push_back(2);
            n -= 2;
        } else {
            // if only 1 left, then either have to change last 3 into 2, 2 or last 2 into a 3
            if (groups.back() == 3){
                groups[groups.size()-1] = 2;
                groups.push_back(2);
            } else {
                groups[groups.size()-1] = 3;
                groups.push_back(1);
            }
            n -= 1;
        }
    }
    cout << groups.size() << endl;
    for(int i = 0; i < groups.size(); i++){
        cout << groups[i] << " ";
    }
    cout << endl;

}

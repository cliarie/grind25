#include <iostream>
#include <vector>

using namespace std;

int main(){
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    int n, temp;
    cin >> n;
    vector<int> indices(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        indices[temp] = i;
    }
    int count = 1;
    for (int i = 2; i <= n; ++i){
        if (indices[i] < indices[i - 1]) count++;
    }
    cout << count << endl;
}

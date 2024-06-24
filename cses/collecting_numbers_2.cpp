#include <iostream>
#include <vector>
#include <set>
#include <utility>
using namespace std;

/*
swap can only affect adjacent values
*/
int main(){
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int n, m, temp;
    cin >> n >> m;
    vector<int> arr(n + 1, 0);
    vector<int> indices(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        indices[arr[i]] = i;
    }

    int count = 1;
    for (int i = 2; i <= n; ++i) {
        if (indices[i] < indices[i - 1]) count++;
    }

    cout << count << endl;;

    set<pair<int, int>> swap;
    for (int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;

        temp = indices[arr[a]];
        indices[arr[a]] = indices[arr[b]];
        indices[arr[b]] = temp;
        int count = 1;
        for (int j = 2; j <= n; ++j){
            if (indices[j] < indices[j - 1]) count++;
        }
        cout << count << endl;
    }
}

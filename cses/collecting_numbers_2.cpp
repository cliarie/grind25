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

    set<pair<int, int>> updatepairs;
    for (int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;

        if (arr[a] + 1 <= n) updatepairs.insert({arr[a], arr[a] + 1});
        if (arr[a] - 1 >= 1) updatepairs.insert({arr[a] - 1, arr[a]});
        if (arr[b] + 1 <= n) updatepairs.insert({arr[b], arr[b] + 1});
        if (arr[b] - 1 >= 1) updatepairs.insert({arr[b] - 1, arr[b]});

        for (auto pair : updatepairs){
            if (indices[pair.first] > indices[pair.second]) count--;
        }
        swap(arr[a], arr[b]);
        swap(indices[arr[a]], indices[arr[b]]);
        for (auto pair : updatepairs){
            if (indices[pair.first] > indices[pair.second]) count++;
        }
        cout << count << endl;
    }
}

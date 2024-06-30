#include <iostream>
#include <vector>
const int INF = 1e9 + 1;
using namespace std;

int main(){
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    struct ranges{
        int left, right, num;
        bool operator<(const ranges& other) const{
            if (left == other.left) return right > other.right;
            return left < other.left;
        }
    };

    int n; cin >> n;
    vector<bool> mother(n, 0), infant(n, 0);
    vector<ranges> arr(n);
    for (int i = 0; i < n; ++i){
        cin >> arr[i].left >> arr[i].right;
        arr[i].num = i;
    }
    sort(arr.begin(), arr.end());

    int rmax = 0;
    for (int i = 0; i < n; ++i){
        if (arr[i].right <= rmax){
            infant[arr[i].num] = 1;
        }
        else rmax = arr[i].right;
    }

    int rmin = INF;
    for (int i = n - 1; i >= 0; --i){

        //cout << rmin << endl;
        if (arr[i].right >= rmin){
            mother[arr[i].num] = 1;
        }
        else rmin = arr[i].right;
    }
    for (auto i : mother) cout << i << " ";
    cout << endl;
    for (auto i : infant) cout << i << " ";
}

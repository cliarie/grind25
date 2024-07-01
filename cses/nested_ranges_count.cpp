#include <iostream>
#include <vector>
const int INF = 1e9 + 1;
using namespace std;

/*
not complete
*/
int main(){
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    struct ranges{
        int left, right, num;
        bool operator<(const ranges& other) const{
            if (left == other.left) return right > other.right;
            return left < other.left;
        }
    };

    int n; cin >> n;
    vector<int> mother(n, 0), infant(n, 0);
    vector<ranges> arr(n);
    for (int i = 0; i < n; ++i){
        cin >> arr[i].left >> arr[i].right;
        arr[i].num = i;
    }
    sort(arr.begin(), arr.end());

    int rmax = 0, maxid;
    for (int i = 0; i < n; ++i){
        if (arr[i].right <= rmax){
            if (i > 0 && arr[i].right <= arr[i - 1].right) {
                infant[arr[i].num] += infant[arr[i - 1].num];
            }
            mother[maxid]++;
        }
        else {
            rmax = arr[i].right;
            maxid = arr[i].num;
        }
    }

    int rmin = INF, minid;
    for (int i = n - 1; i >= 0; --i){
        if (arr[i].right >= rmin){
           // mother[arr[i].num] = 1;
            infant[minid]++;
        }
        else {
            rmin = arr[i].right;
            minid = arr[i].num;
        }
    }
    for (auto i : mother) cout << i << " ";
    cout << endl;
    for (auto i : infant) cout << i << " ";
}

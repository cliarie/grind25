#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    struct guest{
        int start, end, id;
        bool operator<(const guest& other) const {
            if (start == other.start) return end < other.end;
            return start < other.start;
        }
    };

    int n; cin >> n;
    vector<guest> arr(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i].start >> arr[i].end;
        arr[i].id = i;
    }

    sort(arr.begin(), arr.end());
    vector<int> ans(n, 0);
    int count = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> end;
    for (int i = 0; i < n; i++){
        // if (!end.empty()) cout << arr[i].start << " " << end.top().first << " " << end.top().second << ' ';
        // cout <<endl;
        if (!end.empty() && arr[i].start > end.top().first){
            ans[arr[i].id] = ans[end.top().second];
            end.pop();
            end.push({arr[i].end, arr[i].id});
        }
        else {
            count++;
            end.push({arr[i].end, arr[i].id});
            ans[arr[i].id] = count;
        }
    }
    cout << count << endl;
    for (auto i : ans) cout << i << " ";
}

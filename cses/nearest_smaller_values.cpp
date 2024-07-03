#include <iostream>
#include <vector>
#include <stack>
#define ll long long
using namespace std;

/*
stack approach O(n); iterate through array, add value to stack
1. remove all elements greater than current; stack preserves smallest to cur
if stack empty, no elements smaller
otherwise smallest + nearest is top of stack
*/
int main(){
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    int n; cin >> n;
    vector<pair<int, int>> arr(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i].first; arr[i].second = i;
    }

    stack<pair<int, int>> prev;
    for (int i = 1; i <= n; ++i){
        while(!prev.empty() && prev.top().first >= arr[i].first) prev.pop();
        if (prev.empty()) cout << 0 << " ";
        else cout << prev.top().second << " ";
        prev.push(arr[i]);
    }
}

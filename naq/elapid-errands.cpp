// start at (0,0) visit the the points in the order they are given, cannot visit a point twice, find sequence of moves ^ v < > that will visit all points
// visit point in order, can't visit a point more than once
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

    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    for(int i = 0; i < n; i++){
        cin >> points[i].first >> points[i].second;
    }



}

// given n lines of x1, x2, y1, y2 as end points of lines that don't intersect, find the areas of what they enclose. Then find the sum of their squares
// 1 <= n <= 1000
// 0 <= x1, x2, y1, y2 <= 1000

#include <iostream>
#include <vector>

using namespace std;

struct Line{
    int x1, x2, y1, y2;
};

int main(){
    #ifdef LOCAL_TESTING
       freopen("../input.txt", "r", stdin);
       freopen("../output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<Line> lines;
    for(int i = 0; i < n; i++){
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        lines.push_back({x1, x2, y1, y2});
    }

    int area = 0;


}

#include <iostream>
using namespace std;

struct Point{int x; int y;};

double findArea(vector<Point> &polygon){
    int n = polygon.size();
    double area = 0.0;
    for (int i = 0; i < n; ++i){
        int j = (i + 1) % n;
        area += polygon[i].x * polygon[j].y - polygon[j].x * polygon[i].y;
    }
    return fabs(area) / 2.0;
}

pair<int, int> findFraction(int prow, int pcol, vector<pair<int, int>> &polygon){
    vector<Point> corners = {
        {pcol, prow},
        {pcol + 1, prow},
        {pcol + 1, prow + 1},
        {pcol, prow + 1}
    };

    vector<Point> inside;
    for (auto &corner : corners){
        if (isInside(corner, polygon))
    }
}

int main(){
    int n, q; cin >> n >> q;
    vector<pair<int, int>> polygon(n);
    for (int i = 0; i < n; ++i){
        cin >> polygon[i].first >> polygon[i].second;
    }
    for (int i = 0; i < q; ++i){
        int pr, pc; cin >> pr >> pc;

        pair<int, int> fraction = findFraction(pr, pc, polygon);
        cout << fraction.first << "/" <<fraction.second << endl;
    }
}

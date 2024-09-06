#include <iostream>
#include <vector>
#include <map>
using namespace std;

double findDist(const vector<pair<double, int> > &points, int l, int r){
    double ans = 0;
    for (int i = l ; i <= r; ++i){
        ans += points[i].second;
        if (i != l) {
            int tt, tn;
            if (points[i].first > 0) tt = ceil(points[i].first);
            else tt = floor(points[i].first);
            if (points[i - 1].first > 0) tn = ceil(points[i - 1].first);
            else tn = floor(points[i - 1].first);
            ans += tt - tn;
        }
    }
    return ans;
}

int numDistinctWalls(const vector<double> &coords, const vector<int> &thicknesses, int energy){
    // n^2 [-1.5, 0.5, 1.5, 5.5]
    vector<pair<double, int> > points;
    int n = coords.size();
    for (int i = 0; i < n; ++i){
        points.push_back({coords[i], thicknesses[i]});
    }
    points.push_back({0, 0});
    sort(points.begin(), points.end());

    auto it = find_if(points.begin(), points.end(), [](const auto &p) {return p.first == 0.0;});
    int r = it-points.begin() + 1;
    int l = it-points.begin() - 1;
    int cur = it-points.begin();
    int ans = 0;
    while(l >= 0 || r < n){
        cout << l << " " << cur << " " << r << endl;
        int ld = -1, rd = -1;
        if (l >= 0) ld = findDist(points, l, cur);
        if (r < n) rd = findDist(points, cur, r);
        cout << ld << " " << rd << endl;
        if (ld != -1 && rd != -1 && ld < rd || rd == -1){
            cur = l;
            l--;
            energy -= ld;
        }
        else{
            cur = r;
            r++;
            energy -= rd;
        }
        if (energy >= 0) ans++;
    }

    return ans;

}


int main(){
    #ifdef LOCAL_TESTING
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif
    int n, e;
    cin >> n >> e;
    vector<double> coords(n);
    vector<int> thicknesses(n);
    for (int i = 0; i < n; ++i){
        cin >> coords[i] >> thicknesses[i];
    };

    cout << numDistinctWalls(coords, thicknesses, e) << endl;
}

class Solution {
public:

    int findq(double x, double y, vector<vector<int>> towers, double radius){
        int ans = 0;
        for (auto &tower : towers){
            double q = tower[2];
            double d = pow(y - tower[1], 2) + pow(x - tower[0], 2);
            if (d > radius * radius) continue;
            ans += (int)(q / (1 + sqrt(d)));
        }
        return ans;
    }

    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        int maxq = -1;
        vector<int> ans;
        for (int i = 0; i <= 50; ++i){
            for (int j = 0; j <= 50; ++j){
                int q = findq(i, j, towers, radius);
                if (q > maxq){
                    maxq = q;
                    ans = {i, j};
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    bool check(vector<vector<int>> &prefix, int mid, int k){
        int n = prefix.size() - 1, m = prefix[0].size() - 1;
        for (int i = mid; i <= n; ++i){
            for (int j = mid; j <= m; ++j){
                int sum = prefix[i][j] - prefix[i - mid][j] - prefix[i][j - mid] + prefix[i - mid][j - mid];
                if (sum <= k) return true;
            }
        }
        cout << mid << endl;
        return false;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> prefix(n + 1, vector<int> (m + 1, 0));

        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= m; ++j){
                prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }

        int l = 0, r = min(n, m);
        while (r >= l){
            int mid = (l + r) / 2;
            if (check(prefix, mid, threshold)) l = mid + 1;
            else r = mid - 1;
        }
        return r;
    }
};

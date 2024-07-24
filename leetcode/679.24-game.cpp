inline const auto optimize = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return 0;
}();
class Solution {
public:
    vector<double> op(double &a, double &b){
        vector<double> tor = {a + b, a - b, b - a, a * b};
        if (a) tor.push_back(b/a);
        if (b) tor.push_back(a/b);
        return tor;
    }
    bool dfs(vector<double> arr){
        if (arr.size() == 1) return arr[0] >= 23.9 && arr[0] <= 24.1;

        // get all possible two nums
        for (int i = 0; i < arr.size(); ++i){
            for (int j = i + 1; j < arr.size(); ++j){
                double a = arr[i], b = arr[j];
                vector<double> next(arr.begin(), arr.end());
                next.erase(next.begin() + i);
                next.erase(next.begin() + j - 1);
                vector<double> ops = op(a, b);
                // cout << "ON" << a << " " << b << endl;
                // for (auto t : ops) cout << t << " ";
                // cout << endl;
                // for (auto d : next) cout << d << " ";
                // cout << endl;
                for (auto n : ops){
                    next.push_back(n);
                    if (dfs(next)) {
                        return true;
                    }
                    next.pop_back();
                }

                // arr.push_back(a);
                // arr.push_back(b);
            }
        }
        return false;
    }

    bool judgePoint24(vector<int>& cards) {
       // can only use each card once, limited num of possibilities...brute force..backtrack?
       vector<double> arr(cards.begin(), cards.end());
       return dfs(arr);
    }
};

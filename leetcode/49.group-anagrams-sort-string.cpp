class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string, int>> vpairs;
        for (int i = 0; i < strs.size(); ++i){
            string s = strs[i];
            sort(s.begin(), s.end());
            vpairs.push_back({s, i});
        }

        sort(vpairs.begin(), vpairs.end(), [](const auto &a, const auto &b){
            return a.first < b.first;
        });

        vector<vector<string>> result;
        string prev = vpairs[0].first;
        vector<string> cur = {strs[vpairs[0].second]};
        for (int i = 1; i < vpairs.size(); ++i){
            if (vpairs[i].first == prev){
                cur.push_back(strs[vpairs[i].second]);
            } else{
                result.push_back(cur);
                cur = {strs[vpairs[i].second]};
            }

            prev = vpairs[i].first;
        }
        result.push_back(cur);
        return result;
    }
};

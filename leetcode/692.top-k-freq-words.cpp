class Solution {
public:
    struct Comparator{
        bool operator()(const pair<int, string>&a, const pair<int, string>&b){
            return (a.first == b.first) ? a.second > b.second : a.first < b.first;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for (auto w : words) freq[w]++;
        vector<pair<int, string>> vec;
        for (auto it = freq.begin(); it != freq.end(); ++it){
            vec.push_back({it->second, it->first});
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, Comparator> pq(vec.begin(), vec.end());
        vector<string> ans;
        for (auto i = 0; i < k; ++i){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};

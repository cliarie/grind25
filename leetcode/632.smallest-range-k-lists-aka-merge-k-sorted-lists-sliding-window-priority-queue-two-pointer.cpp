#include <vector>
#include <utility>
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int n = nums.size();
        for (int i = 0; i < n; ++i){
            for (auto j : nums[i]){
                pq.push({j, i});
            }
        }

        vector<pair<int, int>> arr;
        while(!pq.empty()){
            const auto& [i, j] = pq.top();
            arr.push_back({j, i});
            pq.pop();
        }

        vector<int> freq(n, 0);
        int counter = n;
        int start = 0, end = 0;
        int a = 0, b = 1e9;

        while(end < arr.size()){
            if (freq[arr[end].first] == 0) counter--;
            freq[arr[end].first]++;
            while(counter == 0){
                if (arr[end].second - arr[start].second < b - a){
                    a = arr[start].second; b = arr[end].second;
                }
                freq[arr[start].first]--;
                if (freq[arr[start].first] == 0) counter++;
                start++;
            }
            end++;
            if (end == arr.size()) break;
        }

        return {a, b};

    }
};

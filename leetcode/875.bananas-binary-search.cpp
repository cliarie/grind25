class Solution {
public:
    bool check(vector<int>& piles, int h, int k){
        if (k == 0) return false;
        long long hrs = 0;
        for (auto i : piles) hrs += (i%k==0) ? (i/k) : i/k + 1;
        // cout << hrs << " " <<  k << endl;
        return hrs <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 0, r = 1e9;
        while (r > l){
            int mid = (r + l) / 2;
            if (check(piles, h, mid)) r = mid;
            else l = mid + 1;
        }
        return r;
    }
};

class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        // toposort ?? 
        vector<vector<int>> rowg(k + 1), colg(k + 1);
        vector<int> rindeg(k + 1), cindeg(k + 1);
        for (auto i : rowConditions){
            rowg[i[0]].push_back(i[1]);
            rindeg[i[1]]++;
        }

        for (auto i : colConditions){
            colg[i[0]].push_back(i[1]);
            cindeg[i[1]]++;
        }
        
        queue<int> rq, cq;
        for (int i = 1; i <= k; ++i){
            if (rindeg[i] == 0) rq.push(i);
        }        
        for (int i = 1; i <= k; ++i){
            if (cindeg[i] == 0) cq.push(i);
        }
        
        int rcount = 0;
        vector<int> rseq;
        while(!rq.empty()){
            int cur = rq.front();
            rq.pop();
            rcount++;
            rseq.push_back(cur);
            for (auto nx : rowg[cur]){
                rindeg[nx]--;
                if (rindeg[nx] == 0) rq.push(nx);
            }
        }
        if (rcount != k) return {}; // has cycle, conflict
        cout << "H" << endl;

        int ccount = 0;
        vector<int> cseq;
        while(!cq.empty()){
            int cur = cq.front();
            cq.pop();
            ccount++;
            cseq.push_back(cur);
            for (auto nx : colg[cur]){
                cindeg[nx]--;
                if (cindeg[nx] == 0) cq.push(nx);
            }
        }
        if (ccount != k) return {}; // has cycle, conflict
        cout << "H" << endl;
        vector<vector<int>> ans(k, vector<int>(k, 0)); // rseq, cseq from 0->n ordered
        for (int i = 0; i < k; ++i){
            for (int j = 0; j < k; ++j){
                if (rseq[i] == cseq[j]) ans[i][j] = rseq[i];
            }
        }
        return ans;

    }
};

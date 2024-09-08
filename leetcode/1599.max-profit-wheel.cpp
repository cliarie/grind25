class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int rotations = 0;
        int profit = 0;
        int maxprofit = 0;
        int oprot = 0;

        int n = customers.size();
        int waiting = 0;
        int i = 0;
        while(i < n || waiting){
            rotations++;
            if (i < n) waiting += customers[i];
            int board;
            if (waiting >= 4) board = 4;
            else board = waiting;

            waiting -= board;
            profit += board * boardingCost - runningCost;
            if (profit > maxprofit){
                maxprofit = profit;
                oprot = rotations;
            }
            ++i;
        }
        if (!oprot) return -1;
        return oprot;
    }
};

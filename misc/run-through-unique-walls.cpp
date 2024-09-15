#include <iostream>
#include <vector>
using namespace std;

int maxWallsPassed(const vector<double>& coords, const vector<int> &thicknesses, int E){
    int n = coords.size();

    vector<pair<double, int>> rightWalls, leftWalls;

    for (int i = 0; i < n; ++i){
        if (coords[i] >= 0.5) rightWalls.push_back({coords[i], thicknesses[i]});
        else leftWalls.push_back({coords[i], thicknesses[i]});
    }
    sort(rightWalls.begin(), rightWalls.end());
    sort(leftWalls.begin(), leftWalls.end(), [](const pair<double, int> &a, const pair<double, int> &b){
        return a.first > b.first;
    });

    int curpos = 0;
    vector<int> rightPrefixSum(rightWalls.size()), leftPrefixSum(leftWalls.size());

    for (int i = 0; i < rightWalls.size(); ++i){
        rightPrefixSum[i] = rightWalls[i].second + floor(rightWalls[i].first) - curpos;
        if (i > 0) rightPrefixSum[i] += rightPrefixSum[i - 1];
        curpos = ceil(rightWalls[i].first);
    }

    curpos = 0;
    for (int i = 0; i < leftWalls.size(); ++i){
        leftPrefixSum[i] = leftWalls[i].second + curpos - ceil(leftWalls[i].first);
        if (i > 0) leftPrefixSum[i] += leftPrefixSum[i - 1];
        curpos = floor(leftWalls[i].first);
    }

    int maxWalls = 0;
    for (int i = 0; i < rightPrefixSum.size(); ++i){
        cout << rightPrefixSum[i] << " " << endl;
        if (rightPrefixSum[i] <= E){
            maxWalls = max(maxWalls, i + 1);
        }
        else break;
    }

    for (int i = 0; i < leftPrefixSum.size(); ++i){
        cout << leftPrefixSum[i] << "? " << endl;

        if (leftPrefixSum[i] <= E){
            maxWalls = max(maxWalls, i + 1);
        }
        else break;
    }

    for (int i = 0; i < rightPrefixSum.size(); ++i){
        for (int j = 0; j < leftPrefixSum.size(); ++j){
            int movementCost = min(rightPrefixSum[i], leftPrefixSum[j]);
            int totalCost = rightPrefixSum[i] + leftPrefixSum[j] + movementCost;
            cout << "POS " << i << " " << j << endl;
            cout << totalCost << " " << movementCost << " " << rightPrefixSum[i] << " " << leftPrefixSum[j] << endl;
            if (totalCost <= E){
                int walls = (i + 1) + (j + 1);
                maxWalls = max(maxWalls, walls);
            }
            else break;
        }
    }

    return maxWalls;

}
int main(){
    vector<double> coords ={-1.5, 0.5, 1.5, 5.5};
    vector<int> thickness = {2, 1, 3, 2};
    cout << maxWallsPassed(coords, thickness, 15) << endl;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item{
    int time;
    double intensity;
};

struct MotionPeriod{
    int start;
    int end;
};

bool compareItem(const Item &a, const Item &b){
    return a.time < b.time;
}

vector<MotionPeriod> motionPeriodsForCamera(vector<Item> &cameraOutput, double threshold){
    sort(cameraOutput.begin(), cameraOutput.end(), compareItem);
    int startTime  = 0;
    int prevTime = 0;
    vector<MotionPeriod> periods;
    for (auto &item : cameraOutput){
        if (item.intensity >= threshold){
            if (!startTime){
                startTime = item.time;
            }
        }
        else{
            if (startTime){
                periods.push_back({startTime, prevTime});
                startTime = 0;
            }
        }
        prevTime = item.time;
    }
    return periods;
}

vector<MotionPeriod> intersection(vector<MotionPeriod> &first, vector<MotionPeriod> &second){
    int fp = 0, sp = 0;
    vector<MotionPeriod> result;
    while(fp < first.size() && sp < second.size()){
        int start = max(first[fp].start, second[sp].start);
        int end = min(first[fp].end, second[fp].end);

        if (start <= end){
            result.push_back({start, end});
        }
        else{
            if (first[fp].end < second[sp].end){
                fp++;
            }
            else sp++;
        }
    }
    return result;
}

vector<MotionPeriod> motionPeriodsForAll(vector<vector<Item>> &cameras, double threshold){
    vector<vector<MotionPeriod>> allPeriods;
    for (auto &camera : cameras){
        vector<MotionPeriod> periods = motionPeriodsForCamera(camera, threshold);
        allPeriods.push_back(periods);
    }
    // two pointer approach, all periods are sorted, find the intersection of k lists
    vector<MotionPeriod> result = allPeriods[0];
    for (int i = 1; i < allPeriods.size(); ++i){
        result = intersection(result, allPeriods[i]);
    }
    return result;
}

int main(){
    vector<Item> cameraOutput = {{2, 0.5}, {7, 0.8}, {10, 0.9}, {11, 0.9}, {16, 0.4}};
    double threshold = 0.8;
    vector<MotionPeriod> result = motionPeriodsForCamera(cameraOutput, threshold); // 7, 11
    for (auto &period : result){
        cout << period.start << " " << period.end << endl;
    }
}

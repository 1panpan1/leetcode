#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals){
        sort(intervals.begin(), intervals.end(), sortFunc);
        vector<vector<int>> result;
        vector<int> tmp ;
        if(intervals.size() > 0)
            tmp = intervals[0];
        else
            return result;
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] <= tmp[1])
                tmp[1] = max(intervals[i][1], tmp[1]);
            else{
                result.push_back(tmp);
                tmp = intervals[i];
            }
        }
        result.push_back(tmp);
        return result;
    }

    vector<vector<int>> merge2(vector<vector<int>>& intervals){
        // more beautiful code
        sort(intervals.begin(), intervals.end(), sortFunc);
        vector<vector<int>> merged;
        for(auto interval:intervals){
            if(merged.empty() || interval[0] > merged.back()[1])
                merged.push_back(interval);
            else
                merged.back()[1] = max(merged.back()[1], interval[1]);
        }
        return merged;
    }

    static bool sortFunc(vector<int>& nums1, vector<int>& nums2){
        return nums1[0] < nums2[0];
    }
};

int main(){
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    Solution solu = Solution();
    vector<vector<int>> merged = solu.merge2(intervals);
    for(auto row:merged){
        for(auto num:row)
            cout<<num<<' ';
        cout<<endl;
    }
    return 0;
}
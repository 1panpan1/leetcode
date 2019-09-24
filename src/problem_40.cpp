#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> array;
        recursive(candidates, result, array, 0, target);
        return result;
    }

    void recursive(vector<int>& candidates, vector<vector<int>>& result, vector<int>& array, int start, int target){
        if(target == 0){
            if(find(result.begin(), result.end(), array) == result.end())
                result.push_back(array);
        }else{
            for(int i = start; i<candidates.size() && candidates[i] <= target; ++i){
                array.push_back(candidates[i]);
                recursive(candidates, result, array, i + 1, target - candidates[i]);
                array.pop_back();
            }
        }
    }
};

int main(){
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    Solution solu = Solution();
    vector<vector<int>> result = solu.combinationSum2(candidates, target);
    for(auto row:result){
        for(auto column:row)
            cout<<column<<' ';
        cout<<endl;
    }
    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		vector<int> tmpInterval;
		vector<vector<int>> result;
		bool inserted = false;
		for(int i = 0; i<intervals.size();){
			if(!inserted && newInterval[0] < intervals[i][0]){
				inserted = true;
				tmpInterval = newInterval;
			}else{
				tmpInterval = intervals[i];
				i++;
			}
			if(result.empty() || tmpInterval[0] > result.back()[1])
				result.push_back(tmpInterval);
			else
				result.back()[1] = max(result.back()[1], tmpInterval[1]);
		}
		if(!inserted) 
			if(result.empty()||newInterval[0] > result.back()[1])
				result.push_back(newInterval);
			else
				result.back()[1] = max(result.back()[1], newInterval[1]);
		return result;
    }
};

int main(){
	Solution solu = Solution();
	vector<int> interval = {4,8};
	// vector<vector<int>> intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}};
	vector<vector<int>> intervals = {};
	vector<vector<int>> result = solu.insert(intervals, interval);
	for(auto row:result){
		for(auto data:row)
			cout<<data<<' ';
		cout<<endl;
	}
	return 0;
}
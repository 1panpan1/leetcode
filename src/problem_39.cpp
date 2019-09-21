#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target){
		sort(candidates.begin(), candidates.end(), less<int>{});
		return combination(candidates, 0, target);
	}

	vector<vector<int>> combination(vector<int>& candidates, int index, int target){
		vector<vector<int>> rst, tmp_1, tmp_2;
		if(index < candidates.size()){
			if(target == candidates[index]){
				rst.push_back(vector<int>{candidates[index]});
				return rst;
			}else if(target > candidates[index]){
				tmp_1 = combination(candidates, index, target - candidates[index]);
				tmp_2 = combination(candidates, index + 1, target);
				if(tmp_1.size() > 0){
					for(auto e:tmp_1){
						e.insert(e.begin(), candidates[index]);
						rst.push_back(e);
					}
				}
				if(tmp_2.size() > 0){
					for(auto e: tmp_2){
						rst.push_back(e);
					}
				}
			}
		}
		return rst;
	}
};

int main(){
	vector<int> candidates = {8, 7, 4, 3};
	int target = 11;
	Solution solu = Solution();
	vector<vector<int>> rst = solu.combinationSum(candidates, target);
	for(auto row:rst){
		for(auto column:row)
			cout<<column<<' ';
		cout<<endl;
	}
	return 0;
}
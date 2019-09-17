#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
	vector<string> generateParenthesis(int n){

	}
};

int main(){
	int n = 4;
	Solution solu = Solution();
	vector<string> rst = solu.generateParenthesis(n);
	for(auto str : rst)
		cout<<str<<endl;
	return 0;
}
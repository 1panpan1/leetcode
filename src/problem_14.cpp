#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution{
public:
	string longestCommonPrefix(vector<string>& strs){
		int count = strs.size();
		int maxlength = 0x7fffffff;
		string common = "";
		if (count > 0){
			for (int i = 0; i < count; ++i){
				if(strs[i].length() < maxlength)
					maxlength = strs[i].length();
			}
			int index;
			for(index = 0; index < maxlength; ++index){
				char tmp = strs[0][index];
				bool stop = false;
				for( int i = 1; i < count; ++i){
					if(strs[i][index] != tmp){
						stop = true;
						break;
					}
				}
				if(stop == true)
					break;
				else
					common += tmp;
			}
		}
		return common;
	}
};

int main(){
	Solution s = Solution();
	vector<string> strs = {};
	cout << s.longestCommonPrefix(strs);
	return 0;
}
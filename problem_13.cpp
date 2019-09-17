#include<iostream>
#include<map>
#include<string>
using namespace std;

class Solution{
public:
	int romanToInt(string s){
		map<char, int> mp = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
		int tmp = 1000;
		int result = 0;

		for(int i = 0; i < s.length(); ++i){
			int cur = mp[s[i]];
			if(cur > tmp){
				result -= 2 * tmp;
				result += cur;
			}else{
				result += cur;
			}
			tmp = cur;
		}
		return result;
	}
};

int main(){
	string s = "I";
	Solution sol = Solution();
	cout <<"int value "<<sol.romanToInt(s)<<endl;
	return 0;
}
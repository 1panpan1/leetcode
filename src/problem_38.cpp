#include<iostream>
#include<string>
using namespace std;

class Solution{
public:
	string countAndSay(int n){
		string seq = "1", newseq = "";
		char his;
		int count;
		for(int i = 1; i < n; ++i){
			count = 1;
			his = seq[0];
			for(int j = 0; j<seq.length() - 1; ++j){
				if(seq[j] == seq[j+1])
					count += 1;
				else{
					newseq += to_string(count) + his;
					his = seq[j+1];
					count = 1;
				}
			}
			newseq += to_string(count) + his;
			seq = newseq;
			newseq = "";
		}
		return seq;
	}
};

int main(){
	int n = 5;
	Solution solu = Solution();
	cout<<solu.countAndSay(n);
	return 0;
}
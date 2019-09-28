#include<iostream>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        long long path = 1;
        int j = min(m, n) - 1;
		int k = m + n - 1 - j;
        for(int i = 1; i<=j;++i){
			path *= k++;
			path /= i;
		}
        return path;
    }
};

int main(){
	int m = 51, n = 9;
	Solution solu = Solution();
	cout<<solu.uniquePaths(m, n);
	return 0;
}
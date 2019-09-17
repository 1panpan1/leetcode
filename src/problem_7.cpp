#include<iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long MAXINT = 2147483647;
        long long MININT = -2147483648;
        int sign = 1;
		long long tmpx = x, ret = 0;
		if(x < 0){
			tmpx = -1 * long(x);
			sign = -1;
		}
		while(tmpx != 0){
			ret *= 10;
			ret += tmpx % 10;
			tmpx /= 10;
		}
		if(ret > MAXINT || ret < MININT) ret = 0;
		return sign * (int)ret;
    }
};

int main(){
    Solution s = Solution();
    cout<<s.reverse(123)<<endl;
    return 0;
}
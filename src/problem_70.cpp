#include<iostream>
using std::cout;
using std::endl;

class Solution {
public:
    int climbStairs(int n) {
        int d[n+1];
        d[0] = d[1] = 1;
        for(int i = 2; i <= n; ++i)
            d[i] = d[i-1] + d[i-2];
        return d[n];
    }
};

int main(){
    Solution solu = Solution();
    cout<<solu.climbStairs(3);
    return 0;
}
#include<iostream>
using namespace std;

class Solution{
public:
    int divide(int dividend, int divisor){
        unsigned int rst = 0;
        unsigned int q = 0;
        unsigned int total = 0;
        int sign1 = dividend >= 0? 1: -1;
        int sign2 = divisor >=0 ?1:-1;
        // if(dividend == 0x80000000 && divisor == -1)
        //     return 0x7fffffff;
        unsigned int abs_dividend = abs(long(dividend));
        unsigned int abs_divisor = abs(long(divisor));
        cout<<abs_dividend<<' '<<abs_divisor<<endl;
        while(abs_dividend - total >= abs_divisor){
            if((total + (abs_divisor << q)) <= abs_dividend){
                rst += 1<<q;
                total += abs_divisor << q;
                q++;
            }else{
                q--;
            }
        }
        if(rst > 0x7fffffff && sign1 == sign2)
            return 0x7fffffff;
        else
            return sign1 == sign2?rst:-rst;
    }
};

int main(){
    Solution solu = Solution();
    int a = -2147483648;
    int b = -1;
    cout<<solu.divide(a, b)<<endl;
    return 0;
}
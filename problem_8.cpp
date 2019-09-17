#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int index = 0, sign = 1, ret = 0;
        int MAX_INT = 2147483647, MIN_INT = -2147483648;
        while(index < str.length() && str[index] == ' ') index++;
        if(index < str.length() && (str[index] == '-' || str[index] == '+' || (str[index] >= '0' && str[index] <= '9'))){
            if(str[index] == '-') {
                sign = -1;
                index++;
            }else if(str[index] == '+') index++;
            while(index < str.length() && str[index] >= '0' && str[index] <= '9'){
                if(sign == 1){
                    if(ret < 214748364 || ret == 214748364 && (str[index] - '0') < 7) ret = ret * 10 + (str[index] - '0');
                    else return MAX_INT;
                }else{
                    if(ret < 214748364 || ret == 214748364 && (str[index] - '0') < 8) ret = ret * 10 + (str[index] - '0');
                    else return MIN_INT;
                }
                index++;
            }
        }      
        return sign * ret;  
    }
};

int main(){
    Solution s = Solution();
    cout<<s.myAtoi("91283472332")<<endl;
    return 0;
}
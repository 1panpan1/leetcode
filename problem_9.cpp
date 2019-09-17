#include<iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        int array[11] = {0}, index = 0;
        if(x < 0) return false;
        while(x != 0){
            array[index] = x % 10;
            x /= 10;
            index++;
        }
        for(int i = 0; i < (index / 2); i++){
            if(array[i] != array[index - 1 - i])
                return false;
        }
        return true;
    }
};

int main(){
    Solution s = Solution();
    cout<<s.isPalindrome(0)<<endl;
    return 0;
}
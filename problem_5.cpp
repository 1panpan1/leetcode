#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int strlength = s.length();
        int maxlength = 0, left = 0, right = 0;
        for(int center = 0; center < strlength; center++){
            //The length of the palindrome string is odd
            int i = center, j = center;
            while(i >= 0 && j < strlength && s[i] == s[j]){
                i--;
                j++;
            }
            if((j - i - 1) > maxlength){
                maxlength = j - i - 1;
                left = i + 1;
                right = j - 1;
            }
            //The length of the palindrome string is even
            i = center, j = center + 1;
            while(i >= 0 && j < strlength && s[i] == s[j]){
                i--;
                j++;
            }
            if((j - i -1) > maxlength){
                maxlength = j - i - 1;
                left = i + 1;
                right = j - 1;
            }
        }
        return s.substr(left, right - left + 1);      
    }
};

int main(){
    Solution s = Solution();
    cout<<s.longestPalindrome("babad")<<endl;
    return 0;
}
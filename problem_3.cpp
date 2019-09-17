#include<iostream>
#include<string>
using namespace std;

class Solution{
public:
    int lengthOfLongestSubstring(string s){
        int strlength = s.length();
        int lptr = 0, rptr = 0;
        int charlen = 200;
        int longest = 0;
        int inSubString[charlen];
        for (int i =0; i<charlen;i++) inSubString[i] = -1;
        while(lptr <= rptr && rptr <strlength){
            if(inSubString[s[rptr]] == -1){
                inSubString[s[rptr]] = rptr;
            }else{
                longest = longest > (rptr - lptr)? longest: (rptr - lptr);
                int tmp = inSubString[s[rptr]];
                for(int i = inSubString[s[rptr]]; i>=lptr; i--) inSubString[s[i]] = -1;
                inSubString[s[rptr]] = rptr;
                lptr = tmp + 1;
            }
            rptr += 1;
        }
        longest = longest>(rptr - lptr)?longest:(rptr - lptr);
        return longest;
    }
};

int main(){
    Solution s = Solution();
    int longest = s.lengthOfLongestSubstring("abba");
    cout<<"longest is "<<longest<<endl;
    return 0;
}
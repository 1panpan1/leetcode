#include<iostream>
#include<string>
using namespace std;

class Solution{
public:
    string convert(string s, int numRows){
        string newstr = s;
        int centerNums = (numRows == 1) ? s.length():(s.length() + 2 * numRows - 2 - 1)/(2 * numRows - 2);
        int groupLen = (numRows == 1) ? 1: 2 * numRows -2;
        int index = 0;
        centerNums += 1;
        for(int step = 0; step <= groupLen / 2; step ++){
            for(int i = 0; i < centerNums; i ++){
                int centerIdx = i * groupLen;
                if((centerIdx - step) >= 0 && (centerIdx - step) < s.length() && s[centerIdx - step] != '\0'){
                    newstr[index] = s[centerIdx - step];
                    s[centerIdx - step] = '\0';
                    index ++;
                }
                if((centerIdx + step) >= 0 && (centerIdx + step) < s.length() && s[centerIdx + step] != '\0'){
                    newstr[index] = s[centerIdx + step];
                    s[centerIdx + step]  = '\0';
                    index ++;
                }
            }
        }
        return newstr;
    }
};

int main(){
    Solution s = Solution();
    cout<<s.convert("", 3);
    return 0;
}
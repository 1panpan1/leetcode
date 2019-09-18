#include<iostream>
#include<string>
using namespace std;

class Solution{
public:
    int strStr(string haystack, string needle){
        for(int i = 0; i <= (haystack.length() - needle.length()); ++i){
            bool find = true;
            for(int j = 0; j<needle.length() && (i+j) < haystack.length(); ++j){
                if(needle[j] != haystack[i+j]){
                    find = false;
                    break;
                }
            }
            if(find == true)
                return i;
        }
        return -1;
    }
};

int main(){
    string haystack = "abcdsdstesdx";
    string needle = "cd";
    Solution solu = Solution();
    int find = solu.strStr(haystack, needle);
    cout<<find<<endl;
    return 0;
}
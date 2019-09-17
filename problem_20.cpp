#include<iostream>
#include<stack>
#include<string>
using namespace std;

class Solution{
public:
    bool isValid(string s){
        string left_brackets = "({[";
        string right_brackets = ")}]";
        stack<char> stk;
        bool valid = true;
        for(int i = 0; i < s.length(); ++i){
            if(left_brackets.find(s[i]) != string::npos){
                stk.push(s[i]);
            }else if(right_brackets.find(s[i]) != string::npos){
                // check validity
                if(stk.empty() == true){
                    valid = false;
                    break;
                }else if(right_brackets.find(s[i]) != left_brackets.find(stk.top())){
                    valid = false;
                    break;
                }else{
                    stk.pop();
                }
            }
        }
        if(stk.empty() != true)
            valid = false;
        return valid;
    }
};

int main(){
    string s = "(";
    Solution solu = Solution();
    cout<<solu.isValid(s)<<endl;
    return 0;
}
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution{
public:
    string multiply(string num1, string num2){
        vector<string> stk;
        int glb_carry = 0;
        string result;
        if(num1 == "0" || num2 == "0")
            return "0";
        for(int i = num1.length() - 1; i >= 0; --i){
            int carry = 0;
            string mul_tmp = "";
            for(int j = num2.length() - 1; j >= 0; --j){
                int digit1 = num1[i] - '0';
                int digit2 = num2[j] - '0';
                int total = digit1 * digit2 + carry;
                mul_tmp = char(total % 10 + '0') + mul_tmp;
                carry = total / 10;
            }
            if(carry > 0)
                mul_tmp = char('0' + carry) + mul_tmp;
            stk.push_back(mul_tmp);
            
            int cal = glb_carry;
            for(int k = 0; k < stk.size(); ++k){
                string tmp = stk[k];
                cal += (tmp[tmp.length() - 1] - '0');
                tmp.pop_back();
                if(tmp == ""){
                    stk.erase(stk.begin() + k);
                    --k;
                }else{
                    stk[k] = tmp;
                }
            }
            result = char(cal % 10 + '0') + result;
            glb_carry = cal / 10;
        }
        while(!stk.empty()){
            int cal = glb_carry;
            for(int k = 0; k < stk.size(); ++k){
                string tmp = stk[k];
                cal += (tmp[tmp.length() - 1] - '0');
                tmp.pop_back();
                if(tmp == ""){
                    stk.erase(stk.begin() + k);
                    --k;
                }else{
                    stk[k] = tmp;
                }
            }
            result = char(cal % 10 + '0') + result;
            glb_carry = cal / 10;
        }
        if(glb_carry > 0)
            result = char(glb_carry + '0') + result;
        return result;
    }
};

int main(){
    string num1 = "123456789", num2 = "987654321";
    Solution solu = Solution();
    cout<<solu.multiply(num1, num2);
    return 0;
}
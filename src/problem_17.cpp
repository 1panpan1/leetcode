#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;

class Solution{
public:
    vector<string> letterCobinations(string digits){
        map<char, string> mp = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8',"tuv"}, {'9', "wxyz"}};
        vector<string> result;
        int total = 1;
        if(digits.length() > 0){
            for(int i = 0; i < digits.length(); ++i)
                total *= mp[digits[i]].length();
            for(int i = 0; i < total; ++i)
                result.push_back("");
            for(int i = 0; i < digits.length(); ++i){
                int index = 0;
                int element_repeat = 1;
                int group_repeat = 1;
                for(int z = i + 1; z < digits.length(); ++z)
                    element_repeat *= mp[digits[z]].length();
                group_repeat = total / element_repeat / mp[digits[i]].length();
                for(int m = 0; m < group_repeat; ++m)
                    for(int n = 0; n < mp[digits[i]].length(); ++n)
                        for(int k = 0; k < element_repeat; ++k){
                            result[index++] += mp[digits[i]][n]; 
                        }
                
            }
        }
        return result;
    }

    vector<string> letterCombinations2(string digits){
        string mp[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result;
        if(digits.length() > 0)
            result = recursive(0, digits,mp);
        return result;
    }

    vector<string> recursive(int index, string digits,string mp[]){
        vector<string> rtn;
        if(index == digits.length()){
            rtn.push_back("");
        }else{
            int digit_index = digits[index] - '2';
            for(int i = 0; i < mp[digit_index].length(); ++i){
                vector<string> combinations = recursive(index + 1, digits, mp);
                for(int j = 0; j < combinations.size(); ++j)
                    rtn.push_back(mp[digit_index][i] + combinations[j]);
            }
        }
        return rtn;
    }
};

int main(){
    string digits = "34";
    Solution solu = Solution();
    vector<string> result = solu.letterCombinations2(digits);
    for(int i = 0; i < result.size(); ++i)
        cout << result[i]<<' ';
    return 0 ;
}
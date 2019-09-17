#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution{
public:
    vector<string> generateParenthesis(int n){
        vector<string> result;
        recursive(result, "", 0, 0, n);
        return result;
    }

    void recursive(vector<string> &result, string cur, int left, int right, int n){
        if(left == right && left == n){
            result.push_back(cur);
            return;
        }
        if(left < n)
            recursive(result, cur + '(', left + 1, right, n);
        if(left > right)
            recursive(result , cur + ')', left, right + 1, n);
    }
};

int main(){
    int n = 4;
    Solution solu = Solution();
    vector<string> rst = solu.generateParenthesis(n);
    for(string element : rst)
        cout<<element<<' ';
    return 0;
}
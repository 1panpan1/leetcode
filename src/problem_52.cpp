#include<iostream>
using namespace std;

class Solution{
public:
    int totalNQueens(int n){
        //int *row = new int[n](); 
        int *column = new int[n](); // initialize every element with 0;
        int *left_slash = new int[2*n - 1]();
        int *right_slash = new int[2*n - 1]();
        int total = 0;
        solve(total, column, left_slash, right_slash, 0, n);
        return total;
    }

    void solve(int& total, int column[], int left_slash[], int right_slash[], int row_index, int n){
        if(row_index == n){
            total += 1;
            return;
        }
        for(int j = 0; j < n; ++j){
            if(column[j] == 0 && left_slash[row_index - j + n - 1] == 0 && right_slash[row_index + j] == 0){
                column[j] = left_slash[row_index - j + n - 1] = right_slash[row_index + j] = 1;
                solve(total, column, left_slash, right_slash, row_index + 1, n);
                column[j] = left_slash[row_index - j + n -1] = right_slash[row_index + j] = 0;
            }
        }
    }
};

int main(){
    int n = 8;
    Solution solu = Solution();
    int total = solu.totalNQueens(n);
    cout<<total<<endl;
    return 0;
}
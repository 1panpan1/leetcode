#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution{
public:
    vector<vector<string>> solveNQueens(int n){
        //int *row = new int[n](); 
        int *column = new int[n](); // initialize every element with 0;
        int *left_slash = new int[2*n - 1]();
        int *right_slash = new int[2*n - 1]();
        vector<vector<string>> solutions;
        vector<string> board;
        string tmp = "";
        for(int i = 0; i < n; i++) tmp += '.';
        for(int i = 0; i < n; i++) board.push_back(tmp);
        solve(solutions, board, column, left_slash, right_slash, 0, n);
        return solutions;
    }

    void solve(vector<vector<string>>& solutions, vector<string>& board, int column[], int left_slash[], int right_slash[], int row_index, int n){
        if(row_index == n){
            solutions.push_back(board);
            return;
        }
        // for row `row_index`, search valide column j to place queen at (row_index, j)
        for(int j = 0; j < n; ++j){
            if(column[j] == 0 && left_slash[row_index - j + n - 1] == 0 && right_slash[row_index + j] == 0){
                column[j] = left_slash[row_index - j + n - 1] = right_slash[row_index + j] = 1;
                board[row_index][j] = 'Q';
                solve(solutions, board, column, left_slash, right_slash, row_index + 1, n);
                board[row_index][j] = '.';
                column[j] = left_slash[row_index - j + n -1] = right_slash[row_index + j] = 0;
            }
        }
    }
};

int main(){
    int n = 8;
    Solution solu = Solution();
    vector<vector<string>> solutions = solu.solveNQueens(n);
    for(auto solution : solutions){
        for(auto e:solution)
            cout<<e<<endl;
        cout<<"==================="<<endl;
    }
    cout<<solutions.size()<<endl;
    return 0;
}
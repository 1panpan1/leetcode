#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    bool isValidSudoku(vector<vector<char>>& board){
        bool valid = true;
        int row[9][10] = {0};
        int column[9][10] = {0};
        int box[3][3][10] = {0};

        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                if(board[i][j] == '.') continue;
                int value = board[i][j] - '0';
                row[i][value] += 1;
                column[j][value] += 1;
                box[i/3][j/3][value] += 1;
                if(row[i][value] > 1 || column[j][value] > 1 || box[i/3][j/3][value] > 1) return false;
            }
        }
        return true;
    }
};

int main(){
    vector<vector<char>> board = {
                                    {'5','3','.','.','7','.','.','.','.'},
                                    {'6','.','.','1','9','5','.','.','.'},
                                    {'.','9','8','.','.','.','.','6','.'},
                                    {'8','.','.','.','6','.','.','.','3'},
                                    {'4','.','.','8','.','3','.','.','1'},
                                    {'7','.','.','.','2','.','.','.','6'},
                                    {'.','6','.','.','.','.','2','8','.'},
                                    {'.','.','.','4','1','9','.','.','5'},
                                    {'.','.','.','.','8','.','.','7','9'}};
    Solution solu = Solution();
    cout<<solu.isValidSudoku(board);
    return 0;
}
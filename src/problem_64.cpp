#include<iostream>
#include<vector>
#include<algorithm>
using std::vector;
using std::cin;
using std::cout;
using std::min;

class Solution{
public:
    int minPathSum(vector<vector<int>>& grid){
        int row = grid.size(), col;
        if(row > 0) col = grid[0].size();
        if(row == 0 || col == 0) return 0;
        int sum[row][col]={};
        sum[0][0] = grid[0][0];
        for(int i = 0; i<row; ++i){
            for(int j = 0; j<col; ++j){
                if(i > 0 && j > 0)
                    sum[i][j] = min(sum[i-1][j], sum[i][j-1]) + grid[i][j];
                else if(i == 0 && j > 0)
                    sum[i][j] = sum[i][j-1] + grid[i][j];
                else if(i > 0 && j == 0)
                    sum[i][j] = sum[i - 1][j] + grid[i][j];
            }
        }
        return sum[row - 1][col - 1];
    }
};

int main(){
    vector<vector<int>> grid = {};
    Solution solu = Solution();
    cout<<solu.minPathSum(grid);
    return 0;
}
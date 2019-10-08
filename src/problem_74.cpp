#include<iostream>
#include<vector>
using std::vector;
using std::cout;
using std::endl;

class Solution{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target){
        if(matrix.size() == 0) return false;
        int i =0, j = matrix.size() * matrix[0].size() - 1, n = matrix[0].size();
        while(i <= j){
            int mid = (i + j) / 2;
            int mid_val = matrix[mid / n][mid % n];
            if(mid_val == target)
                return true;
            else if(mid_val > target)
                j = mid - 1;
            else if(mid_val < target)
                i = mid + 1;
        }
        return false;
    }
};

int main(){
    Solution solu = Solution();
    int target = 9;
    vector<vector<int>> matrix = {{1,   3,  5,  7},
                                {10, 11, 16, 20},
                                {23, 30, 34, 50}};
    cout<<solu.searchMatrix(matrix, target);
    return 0;
}
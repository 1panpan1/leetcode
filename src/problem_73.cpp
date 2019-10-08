#include<iostream>
#include<vector>
using std::vector;
using std::cout;
using std::endl;

class Solution{
public:
    void setZeros(vector<vector<int>>& matrix){
        int flag = -1;
        for(int i = 0; i<matrix.size(); ++i){
            for(int j = 0; j<matrix[0].size(); ++j){
                if(matrix[i][j] == 0){
                    if(j == 0) 
                        flag = 0;
                    else
                        matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for(int i = 1; i < matrix[0].size(); ++i){
            if(matrix[0][i] == 0)
                for(vector<int>& row : matrix)
                    row[i] = 0;
        }
        for(int i = 0; i < matrix.size(); ++i){
            if(matrix[i][0] == 0)
                for(int &e : matrix[i])
                    e = 0;
        }
        if(flag == 0)
            for(vector<int>& row:matrix)
                row[0] = 0;
    }
};

int main(){
    Solution solu = Solution();
    vector<vector<int>> matrix = {{0},{3}};
    solu.setZeros(matrix);
    for(auto row:matrix){
        for(auto e:row)
            cout<<e<<' ';
        cout<<endl;
    }
    return 0;
}
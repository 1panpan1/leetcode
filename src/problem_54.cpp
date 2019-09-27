#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> orderd;
        if(matrix.size() == 0)
            return orderd;
        int xstart = 0, xend = matrix.size() - 1, ystart = 0, yend = matrix[0].size() - 1;
        while(xstart <= xend && ystart <= yend){
            int x, y;
            for(y=ystart;y <= yend;++y)
                orderd.push_back(matrix[xstart][y]);
            for(x = xstart+1; x<=xend; ++x)
                orderd.push_back(matrix[x][yend]);
            if(xstart < xend)
                for(y = yend - 1; y > ystart; y--) orderd.push_back(matrix[xend][y]);
            if(ystart < yend)
                for(x = xend; x > xstart; x--) orderd.push_back(matrix[x][ystart]);
            xstart++;
            ystart++;
            xend--;
            yend--;
        }
        return orderd;
    }
};

int main(){
    vector<vector<int>> matrix = {{2,3,4}};
    Solution solu = Solution();
    vector<int> orderd = solu.spiralOrder(matrix);
    for(int num:orderd)
        cout<<num<<' ';
    return 0;
}
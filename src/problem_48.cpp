#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
		int ystart = 0, yend = matrix.size() - 1, n = matrix.size();
		for(int i = 0; i < n / 2; ++i){
			for(int j = ystart; j < yend; ++j){
				int x = i, y = j, c = 4;
				int pre = matrix[x][y], cur;
				while(c-- > 0){
					cur = matrix[y][n - 1 - x];
					matrix[y][n - 1 - x] = pre;
					pre = cur;
					int t = n - 1 - x;
					x = y;
					y = t;
				}
			}
			ystart++;
			yend --;
		}
    }
};

int main(){
	vector<vector<int>> matrix = {
									{ 5, 1, 9},
									{ 2, 4, 8},
									{13, 3, 6}};
	Solution solu = Solution();
	solu.rotate(matrix);
	for(auto row:matrix){
		for(auto column:row)
			cout<<column<<' ';
		cout<<endl;
	}
	return 0;
}
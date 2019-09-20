#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
	void solveSudoku(vector<vector<char>>& board){
		int row[9][10] = {0};
		int column[9][10] = {0};
		int box[3][3][10] = {0};
		for(int i = 0; i<9; ++i)
			for(int j = 0; j<9; ++j)
				if(board[i][j] != '.'){
					int value = board[i][j] - '0';
					row[i][value]++;
					column[j][value]++;
					box[i/3][j/3][value]++;
				}
		solve(board, row, column, box);
	}

	bool solve(vector<vector<char>>& board, int row[][10], int column[][10], int box[][3][10]){
		for(int x = 0; x < 9; ++x)
			for(int y = 0; y< 9; ++y){
				if(board[x][y] == '.'){
					vector<int> candidates = candidate(row, column, box, x, y);
					if(candidates.size() == 0)
						return false;
					else{
						for(auto value : candidates){
							board[x][y] = value + '0';
							row[x][value] = 1;
							column[y][value] = 1;
							box[x/3][y/3][value] = 1;
							if(true == solve(board, row, column, box))
								return true;
							else{
								board[x][y] = '.';
								row[x][value] = 0;
								column[y][value] = 0;
								box[x/3][y/3][value] = 0;
							}
						}
						return false;
					}
				}
			}
		return true;
	}

	vector<int> candidate(int row[][10], int column[][10], int box[][3][10], int x, int y){
		vector<int> can;
		for(int i = 1; i<=9; ++i)
			if(row[x][i] == 0 && column[y][i] == 0 && box[x/3][y/3][i] == 0)
				can.push_back(i);
		return can;
	}
};

void printBoard(const vector<vector<char>>& board){
	cout<<"+-----------------------+"<<endl;
	for(int i = 0; i < 9; ++i){
		for(int j = 0; j< 9; ++j){
			if(j == 0) cout<<"| ";
			cout<<board[i][j]<<' ';
			if(j % 3 == 2) cout<<"| ";
		}
		cout<<endl;
		if(i % 3 == 2) 
			cout<<"+-----------------------+"<<endl;
	}
}

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
	printBoard(board);
	cout<<endl;
	solu.solveSudoku(board);
	printBoard(board);
	return 0;
}
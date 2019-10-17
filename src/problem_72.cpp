#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::min;

class Solution{
public:
    int minDistance(string word1, string word2){
        const int a = word1.length(), b = word2.length();
        int **dist = new int* [a + 1];
        for(int i = 0; i <= a; ++i) dist[i] = new int[b + 1];
        for(int i = 0; i <= a; ++i) dist[i][0] = i;
        for(int i = 0; i <= b; ++i) dist[0][i] = i;
        for(int i = 1; i <= a; ++i)
            for(int j = 1; j <= b; ++j)
                if(word1[i - 1] == word2[j - 1])
                    dist[i][j] = min(dist[i - 1][j - 1], min(dist[i - 1][j] + 1, dist[i][j - 1] + 1));
                else
                    dist[i][j] =min(dist[i - 1][j - 1] + 1, min(dist[i - 1][j] + 1, dist[i][j - 1] + 1));
        int d = dist[a][b];
        for(int i = 0 ; i <= a; ++i) delete [] dist[i];
        delete [] dist;
        return d;
    }

    int minDistance2(string word1, string word2){
        //使用1个向量来代替2d数组
        // cur数组同时存放了dist[i-1]行的数据和dist[i]行的数据
        const int a = word1.length(), b = word2.length();
        vector<int> cur(b + 1, 0);
        for(int i = 0; i <= b; ++i) cur[i] = i;
        for(int i = 1; i <= a; ++i){
            int pre = cur[0];
            for(int j = 1; j <= b; ++j){
                // temp存放了dist[i-1][j]的值
                // pre存放了dist[i-1][j-1]的值
                // cur[j-1]存放了dist[i][j-1]的值
                int temp = cur[j];
                if(word1[i - 1] == word2[j - 1])
                    cur[j] = pre;
                else
                    cur[j] = min(pre, min(cur[j - 1], cur[j])) + 1;
                pre = temp;
            }
        }
        return cur[b];
    }
};

int main(){
    Solution solu = Solution();
    string word1 = "tt", word2 = "ttion";
    cout<<solu.minDistance2(word1, word2);
    return 0;
}
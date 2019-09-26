// Jump Game 2
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
    int jump(vector<int> & nums){
        int step = 0, i = 0, end = 0, maxend = 0;
        while(end < nums.size() - 1){
            step++;
            for(; i <= end; ++i){
                maxend = max(maxend, i + nums[i]);
                if(maxend >= nums.size() - 1) return step;
            }
            if(end == maxend) break; // cannot reach the last index
            end = maxend;
        }
        return nums.size() == 1 ? 0 : -1;
    }
};

int main(){
    vector<int> input = {16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,1,0};
    Solution solu = Solution();
    cout<<solu.jump(input);
    return 0;
}
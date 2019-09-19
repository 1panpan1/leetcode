#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_l = -1, max_r = -1, max = 0x80000000;
        int i = -1, j= -1, his = 0;
        for(int n = 0; n < nums.size(); ++n){
            if(his <= 0){
                i = j = n;
                his = nums[n];
            }else{
                j = n;
                his += nums[n];
            }
            if(his > max){
                max = his;
                max_l = i;
                max_r = j;
            }
        }
        return max;
    }

    int maxSubArray2(vector<int>& nums){
        // dynamic programming
        int *sum = new int[nums.size()];
        int max_sum;
        max_sum = sum[0] = nums[0];
        for(int i = 1; i<nums.size(); ++i){
            if(sum[i-1] <= 0)
                sum[i] = nums[i];
            else
                sum[i] = sum[i-1] + nums[i];
            max_sum = max_sum < sum[i] ? sum[i] : max_sum;
        }
        delete sum;
        return max_sum;
    }
};

int main(){
    vector<int> nums = {-2,0};
    Solution solu = Solution();
    cout<<solu.maxSubArray2(nums);
    return 0;
}
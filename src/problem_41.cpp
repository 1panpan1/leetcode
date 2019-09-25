#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
    int firstMissingPositive(vector<int>& nums){
        for(int i = 0; i < nums.size(); ){
            if(nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
            else
                ++i;
        }
        for(int i=0; i<nums.size();++i)
            if(nums[i] != (i + 1))
                return i + 1;
        return nums.size() + 1; 
    }
};

int main(){
    vector<int> nums = {7,8,9,1,11,3,5,12,2};
    Solution solu = Solution();
    cout<<solu.firstMissingPositive(nums);
    return 0;
}
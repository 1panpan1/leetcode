#include<iostream>
#include<vector>
using std::cout;
using std::vector;
using std::swap;

class Solution{
public:
    void sortColors(vector<int> &nums){
        int i_0 = 0, i_2 = 0, i = 0;
        int size = nums.size();
        while(i <= (size  - 1 - i_2)){
            if(nums[i] == 0)
                swap(nums[i++], nums[i_0++]);
            else if(nums[i] == 1) 
                i++;
            else if(nums[i] == 2)
                swap(nums[i], nums[size - 1 - i_2++]);
        }
    }
};

int main(){
    vector<int> nums = {2,0,0,1};
    Solution solu = Solution();
    solu.sortColors(nums);
    for(int e : nums)
        cout<<e<<' ';
    return 0;
}
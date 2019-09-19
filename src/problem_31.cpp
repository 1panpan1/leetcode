#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution{
public:
    void nextPermutation(vector<int>& nums){
        int i = nums.size() - 1;
        for(; i > 0; --i){
            if(nums[i] > nums[i-1]){
                int j = i;
                for(; j < nums.size() && nums[j] > nums[i-1]; ++j);
                --j;
                int tmp = nums[j];
                nums[j] = nums[i-1];
                nums[i-1] = tmp;
                sort(nums.begin() + i, nums.end(), less<int>());
                break;
            }
        }
        if(i == 0)
            sort(nums.begin(), nums.end(), less<int>());
    }
};

int main(){
    vector<int> nums = {3,2,5,4,6,3};
    Solution solu = Solution();
    solu.nextPermutation(nums);
    for(auto e:nums)
        cout<<e<<' ';
    return 0;
}
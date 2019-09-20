#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    vector<int> searchRange(vector<int>& nums, int target){
        int left = -1, right = -1;
        int i = 0, j = nums.size() - 1, mid;
        while(i <= j){
            mid = (i + j) / 2;
            if(nums[mid] == target){
                left = mid;
                j = mid - 1;
            }else if(nums[mid] > target)
                j= mid - 1;
            else
                i = mid + 1;
        }
        i = 0;
        j = nums.size() - 1;
        while(i <= j){
            mid = (i + j) / 2;
            if(nums[mid] == target){
                right = mid;
                i = mid + 1;
            }else if(nums[mid] > target)
                j = mid - 1;
            else
                i = mid + 1;
        }
        return vector<int>{left, right};
    }
};

int main(){
    vector<int> nums = {};
    int target = 8;
    Solution solu = Solution();
    vector<int> rst = solu.searchRange(nums, target);
    for(auto e:rst)
        cout<<e<<' ';
    return 0;
}
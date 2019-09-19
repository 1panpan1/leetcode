#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int search(vector<int>& nums, int target){
        int i = 0, j = nums.size() - 1;
        int found = -1;
        while(i <= j){
            int mid = (i + j) / 2;
            if(target == nums[mid]){
                found = mid;
                break;
            }else if(target > nums[mid]){
                if(nums[mid] >= nums[i])
                    i = mid + 1;
                else{
                    if(target <= nums[j])
                        i = mid + 1;
                    else if(target >= nums[i])
                        j = mid - 1;
                    else
                        break;
                }
            }else{
                if(nums[mid] < nums[i])
                    j = mid - 1;
                else{
                    if(target >= nums[i])
                        j = mid - 1;
                    else if(target <= nums[j])
                        i = mid + 1;
                    else
                        break;
                }
            }
        }
        return found;
    }
};

int main(){
    vector<int> nums = {4};
    int target = 4;
    Solution solu = Solution();
    cout<<solu.search(nums, target)<<endl;
    return 0;
}
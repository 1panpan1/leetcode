#include<iostream>
#include<stdlib.h>
#include<vector>
#define min(x, y) (x) < (y) ? (x) : (y)
using namespace std;

class Solution{
public:
    int maxArea(vector<int>& height){
        int size = height.size();
        int max_area = 0;
        for (int left = 0; left < size - 1; left ++){
            for (int right = left + 1; right < size; right ++){
                int area = min(height[left], height[right]) * (right - left);
                if (area > max_area)
                    max_area = area;
            }
        }
        return max_area;
    }
};

int main(){
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    Solution solu = Solution();
    cout << "max area is " << solu.maxArea(height)<<endl;
    return 0;
}
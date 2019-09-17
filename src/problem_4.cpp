#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if(m > n){
            nums1.swap(nums2);
            int tmp = m;
            m = n;
            n = tmp;
        }
        int head = 0, tail = m, mid = (head + tail + 1) / 2;
        while(head <= tail){
            mid = (head + tail) / 2;
            int j = (m + n + 1) / 2 - mid;
            cout<<"mid = "<<mid<<" j = "<<j<<endl;
            if(mid < m && nums1[mid] < nums2[j - 1])
                head = mid + 1;
            else if(mid > 0 && nums1[mid - 1] > nums2[j])
                tail = mid - 1;
            else{
                int maxLeft = 0;
                if(mid == 0) maxLeft = nums2[j - 1];
                else if(j == 0) maxLeft = nums1[mid - 1];
                else maxLeft = nums1[mid - 1] > nums2[j - 1]? nums1[mid - 1]: nums2[j - 1];
                int minRight = 0;
                if(mid == m) minRight = nums2[j];
                else if(j == n) minRight = nums1[mid];
                else minRight = nums1[mid] < nums2[j] ? nums1[mid]: nums2[j];

                if((m+n) % 2 == 1)
                    return double(maxLeft);
                else
                    return (minRight + maxLeft) / 2.0;
            }
        }
        return 0.0;
    }
};

int main(){
    Solution s = Solution();
    vector<int> nums1;
    vector<int> nums2;
    for (int i =1; i<=2; i++){
        nums1.push_back(i);
        nums2.push_back(i + 2);
    }
    for (int i =0; i< nums1.size(); i++){
        cout<<nums1[i]<<' ';
    }
    cout<<endl;
    for (int i =0; i< nums2.size(); i++){
        cout<<nums2[i]<<' ';
    }
    cout<<endl;
    cout<<s.findMedianSortedArrays(nums1, nums2)<<endl;
    return 0;
}
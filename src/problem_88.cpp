#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int total = m + n - 1;
		m--;
		n--;
		while(n >= 0 || m >= 0){
			if(n < 0)
				break;
			else if(m < 0)
				nums1[total--] = nums2[n--];
			else
				nums1[total--] = nums1[m] < nums2[n] ? nums2[n--]: nums1[m--];
		}
    }
};

int main(){
	int m = 3;
	int n = 0;
	vector<int> nums1 = {1,5,8,0,0,0};
	vector<int> nums2 = {};
	Solution solu = Solution();
	solu.merge(nums1, m, nums2, n);
	for(auto e : nums1)
		cout<<e<<' ';
	return 0;
}


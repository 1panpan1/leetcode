#include<iostream>
#include<vector>
#include<stack>
#include<utility>
#include<stdlib.h>
#include<algorithm>
using namespace std;

class Solution{
public:
    int trap(vector<int>& height){
        int rain = 0;
        stack<pair<int, int>> mstack;
        for(int i =0; i< height.size() - 1; i++){
            int difference = height[i + 1] - height[i];
            if(difference < 0) mstack.push(make_pair(difference, i));
            else if(difference > 0 && mstack.size() > 0){
                while(difference > 0 && mstack.size() >0){
                    pair<int, int> tmp = mstack.top();
                    mstack.pop();
                    rain += min(difference, abs(tmp.first)) * (i - tmp.second);
                    difference = difference + tmp.first;
                }
            }
        }
        return rain;
    }
};

int main(){
    Solution s = Solution();
    vector<int> foo;
    vector<int> bar;
    // input: [0,1,0,2,1,0,1,3,2,1,2,1]
    foo.push_back(0);
    foo.push_back(1);
    foo.push_back(0);
    foo.push_back(2);
    foo.push_back(1);
    foo.push_back(0);
    foo.push_back(1);
    foo.push_back(3);
    foo.push_back(2);
    foo.push_back(1);
    foo.push_back(2);
    foo.push_back(1);
    //cout<<s.trap(foo)<<endl;
    cout<<s.trap(bar);
    return 0;
}
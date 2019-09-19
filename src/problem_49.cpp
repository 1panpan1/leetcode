#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

class Solution{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs){
        map<string,vector<string>> map_strs;
        vector<vector<string>> rst;
        for(auto str: strs){
            string key = sortStr(str);
            auto iter = map_strs.find(key);
            if(iter == map_strs.end()){
                map_strs.insert(pair<string, vector<string>>(key, {str}));
            }
            else{
                map_strs[key].push_back(str);    
            }
        }
        for(auto iter = map_strs.begin(); iter != map_strs.end(); ++iter){
            rst.push_back(iter->second);
        }
        return rst;
    }

    string sortStr(string str){
        for(int i = str.length() - 1; i > 0; --i)
            for(int j = 0; j < i; ++j){
                if(str[j] > str[j+1]){
                    char tmp = str[j];
                    str[j] = str[j+1];
                    str[j+1] = tmp;
                }
            }
        return str;
    }
};

int main(){
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution solu = Solution();
    vector<vector<string>> rst = solu.groupAnagrams(strs);
    for(int i = 0; i< rst.size(); ++i){
        for(int j = 0; j<rst[i].size(); ++j)
            cout<<rst[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}
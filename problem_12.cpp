#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution{
public:
    string intToRoman(int num){
        vector<int> splits;
        while(num != 0){
            splits.push_back(num % 10);
            num /= 10;
        }
        reverse(splits.begin(), splits.end());

        char symbols[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        int i = 0;
        string Roman = "";
        while(splits.empty() == false){
            int cur = splits.back();
            cout<<cur<<endl;
            splits.pop_back();
            string roman = "";
            if (cur == 0){
                i += 2;
                continue;
            }else if (cur == 4){
                roman += symbols[i];
                roman += symbols[i + 1];
            }else if (cur < 4){
                while(cur-- > 0)
                    roman += symbols[i];
            }else if (cur == 5){
                roman += symbols[i + 1];
            }else if (cur < 9){
                roman += symbols[i + 1];
                cur -= 5;
                while(cur-- > 0)
                    roman += symbols[i];
            }else if (cur == 9){
                roman += symbols[i];
                roman += symbols[i + 2];
            }
            i += 2;
            Roman = roman + Roman;
        }
        return Roman;
    }
};

int main(){
    int num = 10;
    Solution solu = Solution();
    cout<<"Int: " << num << " Roman: "<< solu.intToRoman(num)<<endl;
    return 0;
}
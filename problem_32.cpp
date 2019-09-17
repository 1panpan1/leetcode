// Problem 32: Longest Valid Parentheses    
#include<iostream>
#include<string>
using namespace std;

int updateStack(int * stack, int ptr){
    while(ptr > 0){
        if (stack[ptr] < 0 && stack[ptr -1] < 0){
            stack[ptr - 1] += stack[ptr];
            ptr -= 1;
        }else
            break;
    }
    // return the top of the stack
    return ptr + 1;
}

int getLongParenthese(string s){
    int * stack = new int[s.length()];
    int ptr = 0;
    int min = 0;
    for (int i = 0; i < s.length(); i++){
        if (s[i] == '('){
            stack[ptr] = i + 1;
            ptr += 1;
        }else if (ptr > 0){
            ptr -= 1;
            if (stack[ptr] < 0){
                // stack[ptr]  is not a '('
                //min = min < stack[ptr]? min : stack[ptr];
                if (ptr == 0){
                    // invalid  ')'
                    stack[ptr] = 0;
                    ptr += 1;
                    continue;
                }else
                    ptr -= 1;
            }
            if (stack[ptr] > 0){
                stack[ptr] = -1 * (i - stack[ptr] + 2); 
                ptr = updateStack(stack, ptr);
                min = min < stack[ptr - 1]? min : stack[ptr - 1];
            }else{
                stack[ptr + 1] = 0;
                ptr += 2;
            }
        }else{
            // Stack is empty. The ')' is invalid
            stack[ptr] = 0;
            ptr += 1;
        }
    }
    return -1 * min;
}

int main(){
    string s = ")))()(((())())))(()()()())";
    int longest = getLongParenthese(s);
    cout<<"longest substring is "<<longest<<endl;
    return 0;
}


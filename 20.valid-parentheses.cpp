/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */
// #include <string>
// #include <utility>
// #include <stack>
// using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> commaStack;
        if(s.empty()){
            return true;
        }
        for(auto c : s) {
            switch (c) {
            case ')':{
                if(commaStack.empty()){
                    return false;
                }
                auto charBuf = commaStack.top();
                commaStack.pop();
                if(charBuf != '('){
                    return false;
                }
            }
                break;
            case ']' :{
                if(commaStack.empty()){
                    return false;
                }
                auto charBuf = commaStack.top();
                commaStack.pop();
                if(charBuf != '['){
                    return false;
                }
            }
                break;
            case '}' :{
                if(commaStack.empty()){
                    return false;
                }
                auto charBuf = commaStack.top();
                commaStack.pop();
                if(charBuf != '{'){
                    return false;
                }
            }
                break;
            default:
                commaStack.push(c);
                break;
            }
        }
        if(commaStack.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};


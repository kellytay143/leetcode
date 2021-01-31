// Source: https://leetcode.com/problems/valid-parentheses/
// Author: Kelly Tay

/**
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
**/

class Solution {
public:
    bool isValid(string s) {
        stack<char> openParen;
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                openParen.push(s[i]);
            }
            else {
                if(openParen.empty()) {
                    return false;
                }
                
                char open = openParen.top();
                openParen.pop();

                if(!matchingParen(open, s[i])) {
                    return false;
                }
            }
        }
        
        if(!openParen.empty()) {
            return false;
        }
        
        return true;
    }
    
    bool matchingParen(char open, char close) {
        return open == '(' && close == ')' || open == '{' && close == '}' || open == '[' && close == ']';
    }
};
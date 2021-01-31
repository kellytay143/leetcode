// Source: https://leetcode.com/problems/backspace-string-compare/
// Author: Kelly Tay

/**
Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Note that after backspacing an empty text, the text will continue empty.
**/

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        //two different stacks
        //iterate through S and T
        //As we iterate, check if the element is a #
            //if it isn't a #, push it onto the stack
            //if it is, pop the top element off the stack
        //After iterating through S and T, pop the top elements off of each stack and compare if are similar
        //if they are similar, continue, if they aren't return false
        //one the stack is empty, return true
        
        stack<char> sStack;
        stack<char> tStack;
        
        for(int i = 0; i < S.size(); i++) {
            if(S[i] == '#') {
                if(sStack.empty()) {
                    continue;
                }
                sStack.pop();
            }
            else {
                sStack.push(S[i]);
            }
        }
        
        for(int i = 0; i < T.size(); i++) {
            if(T[i] == '#') {
                if(tStack.empty()) {
                    continue;
                }
                tStack.pop();
            }
            else {
                tStack.push(T[i]);
            }
        }
        
        while(!sStack.empty() && !tStack.empty()) {
            char sChar = sStack.top();
            char tChar = tStack.top();
            sStack.pop();
            tStack.pop();
            
            if(sChar != tChar) {
                return false;
            }
        }
        
        if(!sStack.empty() || !tStack.empty()) {
            return false;
        }
        return true;
    }
};
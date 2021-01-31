// Source: https://leetcode.com/problems/length-of-last-word/
// Author: Kelly Tay

/**
Given a string s consists of some words separated by spaces, return the length of the last word in the string. If the last word does not exist, return 0.

A word is a maximal substring consisting of non-space characters only.
**/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = s.size();
        int count = 0;
        int i = length;
        while(isspace(s[i - 1]) && (i - 1) >= 0) {
            i--;
        }
        while(!isspace(s[i - 1]) && (i - 1) >= 0) {
            count++;
            i--;
        }
        return count;
    }
};
// Source: https://leetcode.com/problems/reverse-string/
// Author: Kelly Tay

/**
Write a function that reverses a string. The input string is given as an array of characters char[].

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

You may assume all the characters consist of printable ascii characters.
**/

class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i = 0, j = s.size() - 1; i < s.size()/2; i++, j--) {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
     }
};
// Source: https://leetcode.com/problems/valid-anagram/submissions/
// Author: Kelly Tay

/**
Given two strings s and t , write a function to determine if t is an anagram of s.
**/

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        return s == t;
    }
};
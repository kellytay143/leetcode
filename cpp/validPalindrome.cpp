// Source: https://leetcode.com/problems/valid-palindrome/
// Author: Kelly Tay

/**
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.
**/

class Solution {
public:
    bool isPalindrome(string s) {
        string sOnlyAlphaNumeric = "";
        for(int i = 0; i < s.size(); i++) {
            if(isalnum(s[i])) {
                if(isalpha(s[i])) {
                    sOnlyAlphaNumeric += tolower(s[i]);
                }
                else {
                    sOnlyAlphaNumeric += s[i];
                }
            }
        }
        
        int i = 0, j = sOnlyAlphaNumeric.size() - 1;
        while(i < sOnlyAlphaNumeric.size()/2) {
            if(sOnlyAlphaNumeric[i] != sOnlyAlphaNumeric[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
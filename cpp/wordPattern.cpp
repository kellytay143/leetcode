// Source: https://leetcode.com/problems/word-pattern/
// Author: Kelly Tay

/**
Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.
**/

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> patternToS;
        unordered_map<string, char> sToPattern;
        
        string temp = "";
        int patternCnt = 0, sCnt = 0;
        for(int i = 0; i < s.size(); i++) {
            if(!isspace(s[i]) && i != s.size() - 1) {
                temp += s[i];
            }
            else {
                if(patternCnt >= pattern.size()) {
                    return false;
                }
                if(i == s.size() - 1) {
                    temp += s[i];
                }
                if(patternToS.find(pattern[patternCnt]) == patternToS.end()) {
                    if(sToPattern.find(temp) != sToPattern.end()) {
                        return false;
                    }
                    patternToS[pattern[patternCnt]] = temp;
                    sToPattern[temp] = pattern[patternCnt];
                }
                else {
                    if(patternToS[pattern[patternCnt]] != temp) {
                        return false;
                    }
                }
                patternCnt++;
                sCnt++;
                temp = "";
            }
        }
        
        if(pattern.size() > sCnt) {
            return false;
        }
        
        return true;
    }
};
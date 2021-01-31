// Source: https://leetcode.com/problems/longest-common-prefix/
// Author: Kelly Tay
// Date: 12/20/2020

/**
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".
**/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        
        if(strs.empty()) {
            return result;
        }
        
        int shortest = strs[0].size();
        for(int i = 1; i < strs.size(); i++) {
            if(strs[i].length() < shortest) {
                shortest = strs[i].length();
            }
        }
        
        for(int i = 0; i < shortest; i++) {
            char curr = strs[0][i];
            for(int j = 0; j < strs.size(); j++) {
                if(strs[j][i] != curr) {
                    return result;
                }
            }
            result += curr;
        }
        return result;
    }
};
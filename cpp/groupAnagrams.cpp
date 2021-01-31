// Source: https://leetcode.com/problems/group-anagrams/
// Author: Kelly Tay

/**
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
**/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char, int>, vector<string>> resultMap;
        
        for(int i = 0; i < strs.size(); i++) {
            map<char, int> anagramTypes;
            for(int j = 0; j < strs[i].size(); j++) {
                anagramTypes[strs[i][j]]++;
            }
            resultMap[anagramTypes].push_back(strs[i]);
        }
        
        vector<vector<string>> result;
        for(auto it : resultMap) {
            result.push_back(it.second);
        }
        return result;
    }
};
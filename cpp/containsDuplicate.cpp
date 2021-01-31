// Source: https://leetcode.com/problems/contains-duplicate/
// Author: Kelly Tay

/**
Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
**/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> duplicate;
        
        for(int i = 0; i < nums.size(); i++) {
            if(duplicate.find(nums[i]) != duplicate.end()) {
                return true;
            }
            else {
                duplicate.insert(nums[i]);
            }
        }
        return false;
    }
};
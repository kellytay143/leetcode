// Source: https://leetcode.com/problems/subsets/
// Author: Kelly Tay

/**
Given an integer array nums, return all possible subsets (the power set).

The solution set must not contain duplicate subsets.
**/

class Solution {
public:
    vector<vector<int>> result;
    vector<int> subset;
    
    vector<vector<int>> subsets(vector<int>& nums) {
        subsetHelper(nums, 0);
        return result;
    }
    
    void subsetHelper(vector<int>& nums, int index) {
        for(int i = index; i < nums.size(); i++) {
            subset.push_back(nums[i]);
            subsetHelper(nums, i + 1);
            subset.pop_back();
        }
        result.push_back(subset);
    }
    
};
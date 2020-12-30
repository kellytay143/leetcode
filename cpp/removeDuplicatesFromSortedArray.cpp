// Source: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Author: Kelly Tay
// Date: 12/20/2020

/**
Given a sorted array nums, remove the duplicates in-place such that each element appears only once and returns the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
**/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length = 0;
        if(nums.empty()) {
            return length;
        }
        length++;
        
        for(int i = 1, j = 0; i < nums.size() && j < nums.size(); i++) {
            if(nums[i] != nums[j]) {
                length++;
                j++;
                nums[j] = nums[i];
            }
        }
        
        return length;
    }
};
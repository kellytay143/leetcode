// Source: https://leetcode.com/problems/search-insert-position/
// Author: Kelly Tay
// Date: 08/25/2020

/**
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.
**/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        int mid = nums.size() / 2;
        while(left < right) {
            mid = (left + right) / 2;
            if(nums[mid] == target) {
                return mid;
            }
            if(nums[mid] > target) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};

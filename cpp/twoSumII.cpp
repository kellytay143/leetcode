// Source: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// Author: Kelly Tay

/**
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

Note:

Your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution and you may not use the same element twice.
**/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        //if sum is greater than target, decrement right side
        //if sum is less than target, increase left side
        
        int left = 0;
        int right = numbers.size() - 1;
        vector<int> result;
        while(left < right) {
            int sum = numbers[left] + numbers[right];
            if(sum > target) {
                right--;
            }
            else if (sum < target) {
                left++;
            }
            else {
                result.push_back(left+1);
                result.push_back(right+1);
                return result;
            }
        }
        return result;
    }
};
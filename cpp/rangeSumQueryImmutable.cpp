// Source: https://leetcode.com/problems/range-sum-query-immutable/
// Author: Kelly Tay

/**
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
int sumRange(int i, int j) Return the sum of the elements of the nums array in the range [i, j] inclusive (i.e., sum(nums[i], nums[i + 1], ... , nums[j]))
**/

class NumArray {
public:    
    NumArray(vector<int>& nums) {
        int running = 0;
        runningSum.push_back(running);
        for(int i = 0; i < nums.size(); i++) {
            running += nums[i];
            runningSum.push_back(running);
        }
    }
    
    int sumRange(int i, int j) {
        return runningSum[j + 1] - runningSum[i];
    }
    
private:
    vector<int> runningSum;
};

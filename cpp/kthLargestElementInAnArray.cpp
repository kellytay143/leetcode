// Source: https://leetcode.com/problems/kth-largest-element-in-an-array/
// Author: Kelly Tay

/**
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
**/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minQueue;
        
        for(int i = 0; i < nums.size(); i++) {
            minQueue.push(nums[i]);
            if(minQueue.size() > k) {
                minQueue.pop();
            }
        }
        
        return minQueue.top();
    }
};
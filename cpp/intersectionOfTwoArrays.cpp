// Source: https://leetcode.com/problems/intersection-of-two-arrays/
// Author: Kelly Tay

/**
Given two arrays, write a function to compute their intersection.
**/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> nums1Set;
        unordered_set<int> resultSet;
        
        for(int i = 0; i < nums1.size(); i++) {
            if(nums1Set.find(nums1[i]) == nums1Set.end()) {
                nums1Set.insert(nums1[i]);
            }
        }
        
        for(int i = 0; i < nums2.size(); i++) {
            if(nums1Set.find(nums2[i]) != nums1Set.end()) {
                resultSet.insert(nums2[i]);
            }
        }
        
        vector<int> result(resultSet.begin(), resultSet.end());
        return result;
    }
};
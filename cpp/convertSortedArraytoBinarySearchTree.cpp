// Source: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
// Author: Kelly Tay
// Date: 08/30/2020

/**
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
**/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) {
            return nullptr;
        }

        int mid = nums.size()/2;
        TreeNode* root = new TreeNode(nums[mid]);

        //Left half of array
        vector<int> leftNums;
        for(int i = 0; i < mid; i++) {
            leftNums.push_back(nums[i]);
        }

        //Right half of array
        vector<int> rightNums;
        for(int i = mid + 1; i < nums.size(); i++) {
            rightNums.push_back(nums[i]);
        }

        root -> left = sortedArrayToBST(leftNums);
        root -> right = sortedArrayToBST(rightNums);
        return root;
    }
};

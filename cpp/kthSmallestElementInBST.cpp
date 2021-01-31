// Source: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
// Author: Kelly Tay

/**
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
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
    int kthSmallest(TreeNode* root, int k) {
        return inOrderTraverse(root, k);
    }
    
    //in order - left, root, right
    //in order for a BST, put it in order
    
    int inOrderTraverse(TreeNode* root, int& k) {
        if(root && k > 0) {
            int leftSubtreeVal = inOrderTraverse(root -> left, k);
            if(k == 0) {
                return leftSubtreeVal;
            }
            k--;
            if(k == 0) {
                return root -> val;
            }
            return inOrderTraverse(root -> right, k);
        }
        return 0;
    }
};
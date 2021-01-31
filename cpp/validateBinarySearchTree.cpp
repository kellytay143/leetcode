// Source: https://leetcode.com/problems/validate-binary-search-tree/
// Author: Kelly Tay

/**
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

**/

//WIP !!!! Check over answer

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
    TreeNode* prev = NULL;
    
    bool isValidBST(TreeNode* root) {
        //inorder traversal
        //explore the left side of the tree
        //is the curr node bigger than prev? if isn't, return false, if it is, return true
        if(root) {
            if(!isValidBST(root -> left)) {
                return false;
            }
            if(prev == NULL) {
                prev = root;ß
            }
            else {
                if(root -> val < prev -> val) {
                    return false;
                }
                prev = root;
            }
            return isValidBST(root -> right);
        }
        return true;
    }
};
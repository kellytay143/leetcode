// Source: https://leetcode.com/problems/binary-tree-preorder-traversal/
// Author: Kelly Tay

/**
Given the root of a binary tree, return the preorder traversal of its nodes' values.
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
    vector<int> result;
    vector<int> preorderTraversal(TreeNode* root) {
        //preorder = root, left, right
        traverse(root);
        
        return result;
    }
    
    void traverse(TreeNode* root) {
        if(root) {
            result.push_back(root -> val);
            traverse(root->left);
            traverse(root->right);
        }
    }
};
// Source: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
// Author: Kelly Tay

/**
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
**/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //if root > both p and q, that means the ancestor is on the left side of the tree
        //it root < both p and q, ancestor is on the right side of the tree
        //if p < root < q, root is the ancestor
        if(!root) {
            return NULL;
        }
        
        
        /*if((p < root && q > root) || (p > root && q < root)) {
            return root;
        }
        if(p == root || q == root) {
            return root;
        }*/
        if(root->val > p->val && root->val > q->val) {
            return lowestCommonAncestor(root -> left, p, q);
        }
        if(root->val < p->val && root->val < q->val) {
            return lowestCommonAncestor(root -> right, p, q);
        }
        return root;
    }
};
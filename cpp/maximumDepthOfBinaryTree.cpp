// Source: https://leetcode.com/problems/maximum-depth-of-binary-tree/
// Author: Kelly Tay
// Date: 08/26/2020

/**
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Note: A leaf is a node with no children.
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
    int maxDepthRecursive(TreeNode* root) {
        /*Recursive*/
	int leftDepth;
        int rightDepth;
        if(!root) {
            return 0;
        }
        leftDepth = maxDepthRecursive(root -> left);
        rightDepth = maxDepthRecursive(root -> right);
        return max(leftDepth, rightDepth) + 1;
    }

    int maxDepthIterative(TreeNode* root) {
	/*Iterative*/
        int currentMax = 0;
        if(!root) {
            return 0;
        }
        queue<TreeNode*> currentLevel;
        currentLevel.push(root);
        while(!currentLevel.empty()) {
            currentMax++;
            int currentLevelSize = currentLevel.size();
            for(int i = 0; i < currentLevelSize; i++) {
                TreeNode* currentElement = currentLevel.front();
                currentLevel.pop();
                if(currentElement -> left) {
                    currentLevel.push(currentElement -> left);
                }
                if(currentElement -> right) {
                    currentLevel.push(currentElement -> right);
                }
            }
        }
        return currentMax;
    }
};

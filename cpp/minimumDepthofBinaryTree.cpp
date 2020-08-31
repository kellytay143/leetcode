// Source: https://leetcode.com/problems/minimum-depth-of-binary-tree/
// Author: Kelly Tay
// Date: 08/30/2020

/**
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

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
    int minDepth(TreeNode* root) {
        int level = 0;
        queue<TreeNode*> levelQueue;

        if(!root) {
            return level;
        }

        levelQueue.push(root);
        while(!levelQueue.empty()) {
            level++;
            int queueSize = levelQueue.size();
            for(int i = 0; i < queueSize; i++) {
                TreeNode* current = levelQueue.front();
                levelQueue.pop();
                if(!current -> left && !current -> right) {
                    return level;
                }
                if(current -> left) {
                    levelQueue.push(current -> left);
                }
                if(current -> right) {
                    levelQueue.push(current -> right);
                }
            }
        }
        return level;
    }
};

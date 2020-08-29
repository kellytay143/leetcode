// Source: https://leetcode.com/problems/binary-tree-level-order-traversal/
// Author: Kelly Tay
// Date: 08/27/2020

/**
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
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
    vector<vector<int>> levelOrderIterative(TreeNode* root) {
        /*Iterative*/
	vector<vector<int>> levelOrder;
        queue<TreeNode*> levelQueue;
        if(!root) {
            return levelOrder;
        }
        levelQueue.push(root);
        while(!levelQueue.empty()) {
            int sizeQueue = levelQueue.size();
            vector<int> levelVector;
            for(int i = 0; i < sizeQueue; i++) {
                TreeNode* current = levelQueue.front();
                levelQueue.pop();
                levelVector.push_back(current -> val);
                if(current -> left) {
                    levelQueue.push(current -> left);
                }
                if(current -> right) {
                    levelQueue.push(current -> right);
                }
            }
            levelOrder.push_back(levelVector);
        }
        return levelOrder;
    }
 
    vector<vector<int>> levelOrderRecursive(TreeNode* root) {
	/*Recursive*/
	vector<vector<int>> levelOrderResult;
        int levelIndex = 0;
        levelOrderRecursive(levelOrderResult, levelIndex, root);
        return levelOrderResult;
    }

    void levelOrderRecursive(vector<vector<int>>& levelOrderResult, int levelIndex, TreeNode* root) {
        if(!root) {
            return;
        }
        int sizeVecVec = levelOrderResult.size();
        if(sizeVecVec == levelIndex) {
            vector<int> level;
            levelOrderResult.push_back(level);
        }
        levelOrderResult[levelIndex].push_back(root -> val);
        levelOrderRecursive(levelOrderResult, levelIndex + 1, root -> left);
        levelOrderRecursive(levelOrderResult, levelIndex + 1, root -> right);      
    }
};

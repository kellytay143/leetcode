// Source: https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
// Author: Kelly Tay
// Date: 08/27/2020

/**
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        /*Iterative*/
	vector<vector<int>> levelOrder;
        queue<TreeNode*> levelQueue;
        if(!root) {
            return levelOrder;
        }
        levelQueue.push(root);
        while(!levelQueue.empty()) {
            int sizeQueue = levelQueue.size();
            vector<int> level;
            for(int i = 0; i < sizeQueue; i++) {
                TreeNode* current = levelQueue.front();
                levelQueue.pop();
                level.push_back(current -> val);
                if(current -> left) {
                    levelQueue.push(current -> left);
                }
                if(current -> right) {
                    levelQueue.push(current -> right);
                }
            }
            levelOrder.push_back(level);
        }

	//Reverse Function
        /*for(int i = 0; i < (levelOrder.size())/2; i++) {
            vector<int> temp = levelOrder[i];
            levelOrder[i] = levelOrder[(levelOrder.size() - 1) - i];
            levelOrder[(levelOrder.size() - 1) - i] = temp;
        }*/
	
	//C++ Reverse Function
        reverse(levelOrder.begin(), levelOrder.end());
        
	return levelOrder;
    }
};

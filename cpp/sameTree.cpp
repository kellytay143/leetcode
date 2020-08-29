// Source: https://leetcode.com/problems/same-tree/
// Author: Kelly Tay
// Date: 08/27/2020

/**
Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and the nodes have the same value.
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
    bool isSameTreeIterative(TreeNode* p, TreeNode* q) {
        /*Iterative*/
	queue<TreeNode*> pQueue;
        queue<TreeNode*> qQueue;
        pQueue.push(p);
        qQueue.push(q);
        while(!pQueue.empty() && !qQueue.empty()) {
            int sizeQueue = pQueue.size();
            for(int i = 0; i < sizeQueue; i++) {
                TreeNode* pCurrent = pQueue.front();
                TreeNode* qCurrent = qQueue.front();
                pQueue.pop();
                qQueue.pop();
                if(!pCurrent && !qCurrent) {
                    continue;
                }
                if(!pCurrent || !qCurrent) {
                    return false;
                }
                if(pCurrent -> val != qCurrent -> val) {
                    return false;
                }
                pQueue.push(pCurrent -> left);
                pQueue.push(pCurrent -> right);
                qQueue.push(qCurrent -> left);
                qQueue.push(qCurrent -> right);
            }
        }
        return true;
    }

    bool isSameTreeRecursive(TreeNode* p, TreeNode* q) {
	/*Recursive*/
        if(!p && !q) {
            return true;
        }
        if(!p || !q) {
            return false;
        }
        if(p -> val != q -> val) {
            return false;
        }
        bool left = isSameTreeRecursive(p -> left, q -> left);
        bool right = isSameTreeRecursive(p -> right, q -> right);
        return left && right;
    }
};

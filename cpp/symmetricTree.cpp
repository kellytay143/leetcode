// Source: https://leetcode.com/problems/symmetric-tree/
// Author: Kelly Tay
// Date: 08/27/2020

/**
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
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
    bool isSymmetricIterative(TreeNode* root) {
        /*Iterative*/
	queue<TreeNode*> left;
        queue<TreeNode*> right;
        left.push(root);
        right.push(root);
        while(!left.empty() && !right.empty()) {
            int sizeQueue = left.size();
            for(int i = 0; i < sizeQueue; i++) {
                TreeNode* leftCurrent = left.front();
                TreeNode* rightCurrent = right.front();
                left.pop();
                right.pop();
                if(!leftCurrent && !rightCurrent) {
                    continue;
                }
                if(!leftCurrent || !rightCurrent) {
                    return false;
                }
                if(leftCurrent -> val != rightCurrent -> val) {
                    return false;
                }
                left.push(leftCurrent -> left);
                left.push(leftCurrent -> right);
                right.push(rightCurrent -> right);
                right.push(rightCurrent -> left);
            }
        }
        return true;
    }

    bool isSymmetricRecursive(TreeNode* root) {
	/*Recursive*/
	return isSymmetricRecursive(root, root);
    }

    bool isSymmetricRecursive(TreeNode* leftSubtree, TreeNode* rightSubtree) {
        if(!leftSubtree && !rightSubtree) {
            return true;
        }
        if(!leftSubtree || !rightSubtree) {
            return false;
        }
        if(leftSubtree -> val != rightSubtree -> val) {
            return false;
        }
        bool isLeftSym = isSymmetricRecursive(leftSubtree -> left, rightSubtree -> right);
        bool isRightSym = isSymmetricRecursive(leftSubtree -> right, rightSubtree -> left);
        return isLeftSym && isRightSym;
    }
};

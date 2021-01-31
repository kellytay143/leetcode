// Source: https://leetcode.com/problems/linked-list-cycle/
// Author: Kelly Tay
// Date: 12/20/2020

/**
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.
**/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> visitedAddresses;
        
        for(ListNode *curr = head; curr != NULL; curr = curr -> next) {
            if(visitedAddresses.find(curr) == visitedAddresses.end()) {
                visitedAddresses.insert(curr);
            }
            else {
                return true;
            }
        }
        return false;
    }

        bool hasCycle2(ListNode *head) {
        if(head == NULL || head -> next == NULL) {
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head -> next;
        while(slow != NULL && fast != NULL && fast -> next != NULL) {
            if(slow == fast) {
                return true;
            }
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return false;
    }
};
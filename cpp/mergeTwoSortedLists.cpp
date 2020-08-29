// Source: https://leetcode.com/problems/merge-two-sorted-lists/
// Author: Kelly Tay
// Date: 08/25/2020

/**
Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists.
**/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode;
        ListNode* current = head;
        while(l1 && l2) {
            if(l1->val > l2->val) {
                current -> next = l2;
                current = current -> next;
                l2 = l2 -> next;
            } 
            else {
                current -> next = l1;
                current = current -> next;
                l1 = l1 -> next;
            }  
        }
        if(l1) {
            current -> next = l1;
        }
        else {
            current -> next = l2;
        }
        return head -> next;
    }
};

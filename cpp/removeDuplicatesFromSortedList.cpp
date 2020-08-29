// Source: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
// Author: Kelly Tay
// Date: 08/26/2020

/**
Given a sorted linked list, delete all duplicates such that each element appear only once.
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head;
        while(current && current -> next) {
            if(current -> next -> val == current -> val) {
                ListNode* duplicate = current -> next;
                current -> next = duplicate -> next;
                delete duplicate;
            }
            else {
                current = current -> next;
            }
        }
        return head;
    }
};

// Source: https://leetcode.com/problems/palindrome-linked-list/
// Author: Kelly Tay

/**
Given a singly linked list, determine if it is a palindrome.
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
    bool isPalindrome(ListNode* head) {
        if(head == NULL) {
            return true;
        }
        
        ListNode* slow = head;
        ListNode* fast = head -> next;
        ListNode* curr = NULL;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(slow != NULL && fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        curr = slow -> next;
        slow -> next = NULL;
        
        while(curr != NULL) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        
        ListNode* first = head;
        ListNode* second = prev;
        
        while(first != NULL && second != NULL) {
            if(first -> val != second -> val) {
                return false;
            }
            first = first -> next;
            second = second -> next;
        }
        return true;
    }
};

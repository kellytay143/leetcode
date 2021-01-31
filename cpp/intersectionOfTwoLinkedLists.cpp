// Source: https://leetcode.com/problems/intersection-of-two-linked-lists/
// Author: Kelly Tay

/**
Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:
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
    int computeSize(ListNode *head) {
        int size = 0;
        while(head != NULL) {
            size++;
            head = head -> next;
        }
        return size;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //compute size of headA and headB
        //delete the begining of the longer linked list to equal the length of the shorter linked list
        //iterate through both linked list and compare the addresses
        //if the addresses are the same, return the node
        //at the end, if there isn't a match, return null
        
        int headASize = computeSize(headA);
        int headBSize = computeSize(headB);
        
        while(headASize != headBSize) {
            if(headASize > headBSize) {
                headA = headA -> next;
                headASize--;
            }
            else {
                headB = headB -> next;
                headBSize--;
            }
        }

        while(headA != NULL && headB != NULL) {
            if(headA == headB) {
                return headA;
            }
            headA = headA -> next;
            headB = headB -> next;
        }
        return NULL;
    }
};
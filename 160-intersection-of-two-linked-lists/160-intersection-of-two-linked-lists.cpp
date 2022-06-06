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
    int length(ListNode *head){
        int l=0;
        while(head){
            head=head->next;
            l++;
        }
        return l;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
             
        int l1 = length(headA);
        int l2 = length(headB);
        
        while(l1>l2){
            headA=headA->next;
            l1--;
        }
        
        while(l1<l2){
            headB=headB->next;
            l2--;
        }
        
        while(headA != headB){
            headA=headA->next;
            headB=headB->next;
        }
        
        return headA;
        
        
    }
};
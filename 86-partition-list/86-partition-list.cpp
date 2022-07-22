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
ListNode* partition(ListNode* head, int x) {
        if(head==NULL){
            return head;
                
        }
        ListNode* smallHead=new ListNode(0);
        ListNode* largeHead=new ListNode(0);
        ListNode* h1=smallHead;
        ListNode* h2=largeHead;
        while(head){
            int value=head->val;
            if(value<x){
                smallHead->next=head;
                smallHead=smallHead->next;
            }
            else{
                largeHead->next=head;
                largeHead=largeHead->next;
            }
            head=head->next;
        }
        largeHead->next=NULL;
        smallHead->next=h2->next;
        return h1->next;
    }
};
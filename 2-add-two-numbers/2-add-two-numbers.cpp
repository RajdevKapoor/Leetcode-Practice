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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        
        ListNode* head = NULL;
        ListNode* tail = NULL;
        
        int carry =0;
        
        while(l1 or l2){
            
            int v1 = l1 ? l1->val:0;
            int v2 = l2 ? l2->val:0;
            
            int sum = v1+v2+carry;
            
            carry = sum/10;
            sum%=10;
            
            if(head==NULL){
                head = new ListNode(sum);
                tail = head;
            }else{
                tail->next = new ListNode(sum);
                tail = tail->next;
            }

            if(l1){
                l1=l1->next;
            }
            
            if(l2){
                l2=l2->next;
            }
            
        }
        
        if(carry){
            tail->next = new ListNode(carry);
        }
        
        return head;
    }
};
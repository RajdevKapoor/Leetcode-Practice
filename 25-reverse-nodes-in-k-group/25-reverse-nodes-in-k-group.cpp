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
    int length(ListNode* head){
        int len = 0;
        
        while(head){
            head=head->next;
            len++;
        }
        
        return len;
    }
    
    ListNode* addFirst(ListNode* head, ListNode* toAdd){
        if(head == NULL){
            head = toAdd;
            toAdd->next = NULL;
            return head;
        }
        toAdd->next = head;
        head = toAdd;
        return head;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 0){
            return head;
        }
        if(!head || !head->next){
            return head;
        }
        int len = length(head);
        ListNode* oh = NULL;
        ListNode* ot = NULL;
        ListNode* th = NULL;
        ListNode* tt = NULL;
        ListNode* curr = head;
        while(len >= k){
            for(int i = 0; i < k; i++){
                ListNode* next = curr->next;
                if(!th){
                    tt = curr;
                }
                th = addFirst(th, curr);
                curr = next;
                len--;
                
            }
            if(!oh){
                oh = th;
                ot = tt;
            }
            else{
                ot->next = th;
                ot = tt;
            }
            th = NULL;
            tt = NULL;
            
        }
        if(curr){
            ot->next = curr;
            
        }
        else{
            ot->next = NULL;
        }
        return oh;
    }
};
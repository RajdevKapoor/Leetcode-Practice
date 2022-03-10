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
    ListNode* removeElements(ListNode* head, int v) {
        if(head == NULL){
            return head;
        }
        
        while(head and head->val == v){
            head=head->next;
        }
        
        
        ListNode* curr = head;
        
        while(curr and curr->next){
            
                if(curr->next->val == v){
                    curr->next = curr->next->next;
                }
                else{
                    curr = curr->next;
                }
            
        }
        

        
        return head;
    }
};
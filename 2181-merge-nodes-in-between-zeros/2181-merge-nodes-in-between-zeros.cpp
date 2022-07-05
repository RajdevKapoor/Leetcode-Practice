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
    ListNode* mergeNodes(ListNode* head) {
        
        ListNode* left=head;
        ListNode* right=head;
        
        while(right){
            
            if(right->val==0){
                
                left=right;
                right=right->next;
                while(right and right->val !=0){
                    left->val += right->val;
                    right=right->next;
                }
                
                left->next=right;
            } 
        }
        ListNode* temp=head;
        while(temp->next and temp->next->val!=0){
            temp=temp->next;
        }
        temp->next=NULL;
        return head;
    }
};
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
    
    ListNode* reverseList(ListNode* head) {
        
        ListNode* curr=head;
        ListNode* ans =NULL;
        
        while(curr){
            ListNode* temp = curr;
            curr=curr->next;
            temp->next=NULL;
            ans=addFirst(ans,temp);
        }
        
        return ans;
        
    }
};
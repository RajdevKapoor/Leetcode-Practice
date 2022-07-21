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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        
        ListNode* revStart = dummyHead;
               
        for(int i=0;i<left-1;i++){
            revStart=revStart->next;
        }
        
        ListNode* prev = NULL;
        ListNode* curr = revStart->next;
        ListNode* f = NULL;
        
        int k=right-left+1;
        
        ListNode* revEnd=revStart->next;
        
        while(curr and k--){
            f=curr->next;
            curr->next=prev;
            prev = curr;
            curr=f;
        }
        revStart->next=prev;
        revEnd->next=curr;
        
        
        return dummyHead->next;
        
    }
};
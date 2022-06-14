class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) { 
        ListNode* temp=head;
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        if(count/2<1){
            return NULL;
        }
        ListNode* curr=head;
        ListNode* prev=NULL;
        for(int i=0;i<count/2;i++){
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        return head;
    }
};
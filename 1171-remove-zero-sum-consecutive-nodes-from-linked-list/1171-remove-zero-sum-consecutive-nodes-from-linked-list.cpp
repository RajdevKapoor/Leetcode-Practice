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
    ListNode* solve(ListNode* head, bool &flag){
        if(head==NULL) return NULL;
        
        ListNode* temp = head;
        int sum=0;
        
        bool whileCheck = true;
        while(temp){
            sum+=temp->val;
            if(sum==0){
                whileCheck = false;
                flag=true;
                return temp->next;
            }
            temp=temp->next;
        }
        if(whileCheck){
            head->next=solve(head->next,flag);
        }
        
        return head;
    }
    
    ListNode* removeZeroSumSublists(ListNode* head) {
        
        while(true){
            bool flag=false;
            head = solve(head,flag);
            if(head==NULL or flag==false){
                break;
            }
        }
        
        return head;
        
    }
};
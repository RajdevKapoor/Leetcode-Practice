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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        int length = 0;
        vector<ListNode*> ans;
        
        ListNode* temp = head;
        while(temp){
            length++;
            temp=temp->next;
        }
        
        int sets = length / k;
        int r = length % k;
        
        ListNode* curr=head;
        
        while(curr){
            
            ans.push_back(curr);
            int stop = (r>0)?sets:sets-1;
            for(int i=0 ;i< stop  ;i++){
                if(curr == NULL){
                    break;
                }
                curr=curr->next;
            }
            r--;
            if(curr == NULL){
                break;
            }
            ListNode* prev=curr;
            curr=curr->next;
            prev->next =NULL;
        }
        
        while(ans.size()<k){
            ans.push_back(NULL);
        }
        
        return ans;
        
    }
};
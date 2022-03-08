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
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* l3 = NULL;
       
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        if(l1->val > l2->val){
            l3 = l2;
            l2 = l2->next;
        }else{
            l3 = l1;
            l1 = l1->next;
        }
        
        ListNode* temp = l3;
        
        while(l1 and l2){
            
            if(l1->val > l2->val){
                temp->next = l2;
                l2 = l2->next;
            }else{
                temp->next = l1;
                l1 = l1->next;
            }
            
            temp=temp->next;
            
        }
        
        if(l1!=NULL){
            temp->next = l1;
        }else{
            temp->next = l2;
        }
        
        return l3;
        
    }
    
    
    ListNode* mergeKLists(vector<ListNode*>& l) {
        
        if(l.size() == 0) return 0;
        if(l.size() == 1) return l[0];
        
        ListNode* ans = mergeTwoLists(l[0],l[1]);
        
        for(int i=2;i<l.size();i++){
            ans = mergeTwoLists(ans,l[i]);
        }
        
        return ans;
        
    }
};
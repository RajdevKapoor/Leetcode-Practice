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
    ListNode* left;
    
    bool helper(ListNode* right){
        if(right==NULL) return true;
        
        bool rres = helper(right->next);
        
        if(rres==false){
            return false;
        }
        else if( left->val != right->val){
             return false;
        }
        
        else{
            left=left->next;
            return true;
        }
        
        
    }
    
    bool isPalindrome(ListNode* head) {
        
        left=head;
        return helper(head);
        
        
        
    }
};
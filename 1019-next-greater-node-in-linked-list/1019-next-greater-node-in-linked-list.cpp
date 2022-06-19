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
    vector<int> nextLargerNodes(ListNode* head) {
        
        stack<int>s;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forw = NULL;
        
        while(curr){
            forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr=forw;
        }
        
        head = prev;
        ListNode* temp = head;
        
        vector<int> ans;
        
        while(temp){
            
            while(s.size()>0 and s.top()<=temp->val){
                s.pop();
            }
            
            s.empty()? ans.push_back(0):ans.push_back(s.top());
            
            s.push(temp->val);
            temp=temp->next;
            
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
        
        
    }
};
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
private:
    int size = 0;
    ListNode* curr;
public:
    Solution(ListNode* head) {
        curr=head;
        while(curr->next){
            size++;
            curr=curr->next;
        }
        
        curr->next=head;
        curr=curr->next;
        size++;
        
    }
    
    int getRandom() {
        int r = rand()%size;
        
        while(r--){
            curr=curr->next;
        }
        
        return curr->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
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

    ListNode* rev(ListNode* root){
        ListNode* rev = NULL, *tmp = root;
        while(tmp){
            ListNode* ptr = tmp;
            tmp = tmp->next;
            ptr->next = rev;
            rev = ptr;
        }
        return rev;
    }

    int len(ListNode* root){
        ListNode* tmp = root;
        int l = 0;
        while(tmp){
            tmp = tmp->next;
            l++;
        }
        return l;
    }

    int pairSum(ListNode* head) {
        int n = len(head);
        n /= 2;
        ListNode* tmp = head;
        for(int i = 0; i < n-1; i++) tmp = tmp->next;
        ListNode* second = tmp->next;
        tmp->next = NULL;
        tmp = head;
        second = rev(second);
        int res = 0;
        while(second){
            res = max(res, tmp->val+second->val);
            tmp = tmp->next;
            second = second->next;
        }
        return res;
    }
};
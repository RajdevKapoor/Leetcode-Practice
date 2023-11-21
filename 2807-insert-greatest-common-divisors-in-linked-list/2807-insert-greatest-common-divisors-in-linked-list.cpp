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
    int gcd(int a, int b)
    {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* ll=head;
        while(ll->next!=NULL){
            int k1=ll->val;
            int k2=ll->next->val;
            ListNode* nn=new ListNode(gcd(k1,k2));
            nn->next=ll->next;
            ll->next=nn;
            ll=ll->next->next;
        }
        return head;
    }
};
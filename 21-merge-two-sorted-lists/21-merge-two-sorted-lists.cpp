class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(list1 == NULL && list2 == NULL){
            return list1;
        }
        if(list1 == NULL){
           return list2; 
        }else if(list2 == NULL){
            return list1;
        }
        ListNode* listResHead =  new ListNode(min(list1->val,list2->val));
        ListNode* listResCurr = listResHead; 
        
        if(list1->val < list2->val){
            list1=list1->next;
        }else{
            list2 = list2->next;
        }
        
        while(list1 != NULL && list2 != NULL){
           
            ListNode* temp = new ListNode();
            
            if(list1->val < list2->val){
                temp->val = list1->val;
                list1 = list1->next;
            }else{
                temp->val = list2->val;
                list2 = list2->next;
            }
        
            listResCurr->next = temp;
            listResCurr = listResCurr->next;
            
        }
        
        if(list1!=NULL){
            listResCurr->next = list1;
        }else{
            listResCurr->next = list2;
        }
        return listResHead;
    }
};
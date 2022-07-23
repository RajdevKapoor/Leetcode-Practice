class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* list3 = NULL; 
        
        if(list1 == NULL && list2 == NULL){
            return NULL;
        }
        if(list1 == NULL){
           return list2; 
        }else if(list2 == NULL){
            return list1;
        }
        
        if(list1->val > list2->val){
            list3 = list2;
            list2 = list2->next;
        }else{
            list3 = list1;
            list1 = list1->next;
        }
        
        ListNode* temp = list3;
        
        while(list1 != NULL && list2 != NULL){
           
            
            if(list1->val < list2->val){
                temp->next = list1;
                list1=list1->next;
            }else{
                temp->next = list2;
                list2 = list2->next;
            }
        
            temp = temp->next;
        }
        
        if(list1!=NULL){
            temp->next = list1;
        }else{
            temp->next = list2;
        }
        
        return list3;
    }
};
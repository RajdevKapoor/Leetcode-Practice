class Node{
public:

int data;
Node* next;
Node(int x){
    data = x;
    next = NULL;
}
};

class MyLinkedList {
public:
Node* head;

MyLinkedList() {
    head = NULL;
}

int get(int index) {
    
    if(head == NULL || index < 0)
        return -1;
    
    Node* temp = head;
    
    while(index != 0){
        if(temp == NULL)
            return -1;
        temp = temp->next;
        index--;
    }
    
    if(temp == NULL)
        return -1;
    return temp->data;
}

void addAtHead(int val) {
    
    Node* temp = new Node(val);
    temp->next = head;
    head = temp;
}

void addAtTail(int val) {
     
     Node* temp = new Node(val);
     if(head == NULL){
         head = temp;
         return;
     }
    
     Node* curr = head;
     while(curr->next != NULL){
         curr = curr->next;
     }
    
     curr->next = temp;
}

void addAtIndex(int index, int val) {
     
     if(index == 0)
         addAtHead(val);
     else if(index > 0 && head==NULL)
         return;
     else{
         Node* curr = head;

         while(index != 1){
             curr = curr->next;
             if(curr == NULL)
                 return;
             index--;
         }
         
         Node* temp = new Node(val);
         temp->next = curr->next;
         curr->next = temp;

     }
}

void deleteAtIndex(int index) {
    if(index < 0)
        return;
    
    if(head == NULL)
        return;
    
    if(index == 0){
        head = head->next;
        return;
    }
    
    Node* curr = head;
    while(index != 1){
        curr = curr->next;
        if(curr == NULL)
            return;
        index--;
    }
    
    if(curr->next && curr->next->next != NULL){
        curr->next = curr->next->next;
    }else{
        curr->next = NULL;
    }
}
};
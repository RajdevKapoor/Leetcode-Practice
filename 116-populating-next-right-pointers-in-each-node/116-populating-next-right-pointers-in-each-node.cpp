/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        if(root==NULL){
            return root;
        }
        
        queue<Node*> q;
        q.push(root);
        
        while(q.size()){
            int sz=q.size();
            
            for(int i=0;i<sz;i++){
                auto tmp = q.front();
                q.pop();
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
                
                tmp->next = q.front();
                
                if(i==sz-1){
                    tmp->next=NULL;
                }
            }
        }
        return root;
    }
};
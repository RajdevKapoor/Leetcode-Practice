/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class CBTInserter {
private:
   TreeNode* rut=NULL;
    queue<TreeNode*>q;
public:
    CBTInserter(TreeNode* root) {
        
        rut=root;
       
        q.push(root);
        bool flag=0;
        while(!q.empty())
        {
            int sz=q.size();
            for(int i=0;i<sz;++i)
            {
                TreeNode* curr=q.front();
                if(curr->left)
                    q.push(curr->left);
                else
                    flag=1;
                
                if(curr->right)
                    q.push(curr->right);
                else
                    flag=1;
                if(!flag)
                    q.pop();
                else
                    break;
            }
            if(flag)
                break;
        }
        
        
    }
    
    int insert(int val) {
        TreeNode* newNode=new TreeNode(val);
        TreeNode* curr=q.front();
        if(!curr->left)
        {
            curr->left=newNode;
            q.push(curr->left);
        }
        else
        {
            curr->right=newNode;
            q.push(curr->right);
            q.pop();
        }
        return curr->val;
        
    }
    
    TreeNode* get_root() {
        return rut;
    }
};
/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
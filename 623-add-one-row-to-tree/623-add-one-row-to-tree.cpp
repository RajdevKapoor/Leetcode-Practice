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
class Solution {
public:
    void solve(TreeNode* root,int val,int depth){
        if(root==NULL) return;
        
        if(depth==1){
            
            TreeNode* l = root->left;
            TreeNode* r = root->right;
            
            root->left = new TreeNode(val,l,NULL); 
            root->right =new TreeNode(val,NULL,r); 
        }
        else{
            solve(root->left,val,depth-1);
            solve(root->right,val,depth-1);
        }
        
        
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(depth==1){
            
            TreeNode* nroot = new TreeNode(val);
            nroot->left = root;
            return nroot;
                
                
        }
        solve(root,val,depth-1);
        return root;
    }
};
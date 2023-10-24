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
    bool solve(TreeNode* root){
        if(root==NULL){
            return 1;
        }
        
        if(root->left == NULL and root->right==NULL){
            if(root->val){
                return true;
            }else{
                return false;
            }
        }
        
        bool l = evaluateTree(root->left);
        bool r = evaluateTree(root->right);
        
        if(root->val == 2){
            return l|r;
        }
        if(root->val == 3){
            return l&r;
        }
        
        return root->val;
    }
    
    bool evaluateTree(TreeNode* root) {
    
        return solve(root);
    }
};
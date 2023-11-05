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
    
    int ans=0;
    
    int solve(TreeNode* root) {
        
        if(root==NULL){
            return 1;
        }
        
        int lchild = solve(root->left);
        int rchild = solve(root->right);
        
        if(lchild==-1 or rchild==-1){
            ans++;
            return 0;
        }
        
        if(lchild==0 or rchild==0){
            return 1;
        }
        
        return -1;
        
    }
    
    int minCameraCover(TreeNode* root) {
        
        return solve(root)==-1?ans+1:ans;
        
    }
};
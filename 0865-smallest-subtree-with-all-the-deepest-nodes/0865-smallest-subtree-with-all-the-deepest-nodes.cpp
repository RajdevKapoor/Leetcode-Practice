class Solution {
public:
    int height(TreeNode* root){
        if(root==NULL) return 0;
        
        int l=height(root->left);
        int r=height(root->right);
        
        return (max(l,r)+1);
    }
    
    void fun(TreeNode* root,TreeNode* &ans){
        int left=height(root->left);
        int right=height(root->right);
        
        if(left>right)
        {
            fun(root->left,ans);
        }
        if(left<right)
        {
            fun(root->right,ans);
        }
          if(left==right)
        {
            ans=root;
        }
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        TreeNode* ans=NULL;
        fun(root,ans);
        return ans;
    }
};

class Solution {
public:
    int m=INT_MAX,sm=INT_MAX;
    bool check=0;
    void helper(TreeNode* root)
    {
        if(root==NULL)
            return;
        if(root->val<m)
            m=root->val; 
        else if(root->val>m)
        {
            sm=min(sm,root->val); 
            check=1;
        }
        helper(root->left);
        helper(root->right);
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        helper(root);
        if(sm==INT_MAX and check==0)
            return -1;
        return sm;
    }
};
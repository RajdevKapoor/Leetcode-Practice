
class Solution {
public:
    
    bool check=0;
    void helper(TreeNode* root,int &m,int &sm)
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
        helper(root->left,m,sm);
        helper(root->right,m,sm);
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        int m=INT_MAX,sm=INT_MAX;
        helper(root,m,sm);
        if(sm==INT_MAX and check==0)
            return -1;
        return sm;
    }
};
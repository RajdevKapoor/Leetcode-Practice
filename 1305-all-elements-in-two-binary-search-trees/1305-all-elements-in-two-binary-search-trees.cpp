class Solution {
public:
    void inorder(TreeNode *root,vector<int>& a)
    {
        if(root==NULL)
            return ;
            inorder(root->left,a);
            a.push_back(root->val);
            inorder(root->right,a);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> a;
        vector<int> b;
        inorder(root1,a);
        inorder(root2,b);
        int m=a.size();
        int n=b.size();
        vector<int> res;
        int i=0,j=0;
        while(i<m && j<n)
        {  
            if(a[i]>=b[j])
            {
                res.push_back(b[j]);
                j++;
            }
            else
            {
                res.push_back(a[i]);
                i++;
            }
            
            
        }
        while(i<m)
        {
            res.push_back(a[i]);
            i++;
        }
         while(j<n)
        {
            res.push_back(b[j]);
            j++;
        }
        
        return res;
    }
};
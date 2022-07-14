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
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int &preIndex,int start,int end)
    {
        if(start>end)
        {
            return NULL;
        }
        TreeNode*root=new TreeNode(preorder[preIndex]);
        preIndex++;
        int inIndex;
        for(int i=start;i<=end;i++)
        {
            if(inorder[i]==root->val)
            {
                inIndex=i;
                break;
            }
        }
        root->left=helper(preorder,inorder,preIndex,start,inIndex-1);
        root->right=helper(preorder,inorder,preIndex,inIndex+1,end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        int preIndex=0;
        int start=0;
        int end=preorder.size()-1;
        return helper(preorder,inorder,preIndex,start,end);
    }
};
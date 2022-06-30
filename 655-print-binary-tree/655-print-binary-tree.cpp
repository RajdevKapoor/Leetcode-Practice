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
    int height(TreeNode* root){
        if(root==NULL)return 0;
        
        int l = height(root->left);
        int r = height(root->right);
        
        return 1+max(l,r);
        
    }
    
    void solve(TreeNode* root, int row,int s,int end,vector<vector<string>> &ans){
        
        if(root==NULL) return;
        
        int mid = s+(end-s)/2;
        ans[row][mid]=to_string(root->val);
        
        solve(root->left,row+1,s,mid-1,ans);
        solve(root->right,row+1,mid+1,end,ans);
        
    }
    
    vector<vector<string>> printTree(TreeNode* root) {
        int h = height(root);
        int r = pow(2,h)-1;
        
        vector<vector<string>> ans(h, vector<string>(r, ""));
        
        solve(root,0,0,ans[0].size(),ans);
        
        return ans;
    }
};
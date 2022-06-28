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
    void solve(TreeNode* root,int lvl,vector<vector<int>> &ans){
        
        if(root==NULL) return;
        
        if(ans.size()==lvl){
            ans.push_back({});
        }
        
        ans[lvl].push_back(root->val);
        solve(root->left,lvl+1,ans);
        solve(root->right,lvl+1,ans);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        solve(root,0,ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
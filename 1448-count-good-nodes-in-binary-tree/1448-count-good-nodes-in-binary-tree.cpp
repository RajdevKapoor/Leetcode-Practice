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
    
    int ans;
    
    void solve(TreeNode* root, int msf){
        
        if(root==NULL) return;
        
        if(root->val >= msf){
            msf = root->val;
            ans++;
        }
        
        solve(root->left,msf);
        solve(root->right,msf);
        
    }
    
    int goodNodes(TreeNode* root) {
        
        ans=0;
        
        solve(root,INT_MIN);
        
        return ans;
        
    }
};
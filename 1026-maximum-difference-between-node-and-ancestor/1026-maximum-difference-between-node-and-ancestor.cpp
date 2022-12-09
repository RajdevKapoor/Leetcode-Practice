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
    int solve(TreeNode* root, int minv, int maxv){
        
        if(root==NULL){
            return  (maxv - minv);
        }
        
        minv = min(minv,root->val);
        maxv = max(maxv,root->val);
        
        return max(solve(root->left,minv,maxv),solve(root->right,minv,maxv));
        
    }
    int maxAncestorDiff(TreeNode* root) {
        
        if(root==NULL) return 0;
        
        return solve(root,root->val,root->val);
        
    }
};
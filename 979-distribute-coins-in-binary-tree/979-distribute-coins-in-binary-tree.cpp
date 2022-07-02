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
    int sum=0;
    
    int solve(TreeNode* root) {
        
        if(root==NULL) return 0;
        
        int lc = solve(root->left);
        int rc = solve(root->right);
        sum+=abs(lc)+abs(rc);
        
        return (lc+rc+root->val-1);
        
    }
    int distributeCoins(TreeNode* root) {
        solve(root);
        return sum;
    }
};
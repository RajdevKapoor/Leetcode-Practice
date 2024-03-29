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
    bool solve(TreeNode* root, int targetSum, int sum){
        
        if(root==NULL) return false;
        
        sum+=root->val;
        
        if(sum==targetSum and root->left==NULL and root->right==NULL){
            return true;
        }
        
        return solve(root->left,targetSum,sum) or solve(root->right,targetSum,sum);
        
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        return solve(root,targetSum,0);
        
    }
};
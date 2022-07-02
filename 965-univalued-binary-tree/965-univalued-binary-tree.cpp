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
    bool isUnivalTree(TreeNode* root) {
        
        if(root==NULL) return true;
        
        if(root->left and root->val != root->left->val) return false;
        if(root->right and root->val != root->right->val) return false;
        
        return isUnivalTree(root->left) and isUnivalTree(root->right);
        
    }
};
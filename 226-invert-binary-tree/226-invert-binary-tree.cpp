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
    void exchange(TreeNode* root){
        
        if(root==NULL) return;
        
        if(root->left==NULL and root->right==NULL){
            return;
        }
        if(root->left==NULL){
            root->left=root->right;
            root->right = NULL;
            exchange(root->left);
            return;
        }
        if(root->right==NULL){
            root->right=root->left;
            root->left = NULL;
            exchange(root->right);
            return;
        }
        
        TreeNode* temp  = root->left;
        root->left = root->right;
        root->right = temp;
        exchange(root->left);
        exchange(root->right);
        
        return;
    }
    TreeNode* invertTree(TreeNode* root) {
        exchange(root);
        return root;
    }
};
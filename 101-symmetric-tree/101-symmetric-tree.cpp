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
    
    bool help(TreeNode* left,TreeNode* right){
        if(left==NULL and right==NULL){
            return true;
        }
        if((left == NULL and right != NULL) or (right == NULL and left != NULL)){
            return false;
        }
        if(left->val != right->val){
            return false;
         }
        return help(left->left,right->right) and help(left->right,right->left);
            
    }
    
    
    bool isSymmetric(TreeNode* root) {
        return root==NULL || help(root->left, root->right);
    }
};
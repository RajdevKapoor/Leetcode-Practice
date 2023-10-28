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
    bool same(TreeNode* root, TreeNode* subRoot) {
        
        if(root == NULL and subRoot == NULL) return true;
        if(root == NULL or subRoot == NULL) return false;
        
        if(root->val==subRoot->val){
            return same(root->left,subRoot->left) and same(root->right,subRoot->right);
        }
        
        return false;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL and subRoot == NULL) return true;
        if(subRoot == NULL) return true;
        if(root == NULL) return false;
        
        return same(root,subRoot) or isSubtree(root->left,subRoot) or isSubtree(root->right,subRoot);
    }
};
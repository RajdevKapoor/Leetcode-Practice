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
private:
    int sum = 0;
public:
    void reverseInordered(TreeNode* root){
        if(root==NULL) return;
        
        reverseInordered(root->right);
        sum+=root->val;
        root->val =  sum;
        reverseInordered(root->left);
        
        return;
    }
    
    TreeNode* convertBST(TreeNode* root) {
        reverseInordered(root);
        return root;
    }
};
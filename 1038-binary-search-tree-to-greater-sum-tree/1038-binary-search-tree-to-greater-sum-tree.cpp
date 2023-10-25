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
    int cursum = 0;
public:
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->right);
        cursum += root->val;
        root->val = cursum;
        inorder(root->left);
    }   

    TreeNode* bstToGst(TreeNode* root) {
        cursum = 0;
        inorder(root);
        return root;
    }
};
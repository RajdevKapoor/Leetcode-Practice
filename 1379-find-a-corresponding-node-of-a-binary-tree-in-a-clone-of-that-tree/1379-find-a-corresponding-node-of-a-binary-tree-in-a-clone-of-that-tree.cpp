/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* val = NULL;
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        traverse(original, cloned, target);
        return val;
    }
    void traverse(TreeNode* original, TreeNode* cloned, TreeNode* target)
    {
        if(original == NULL || val != NULL)
            return;
        if(original == target)
            val = cloned;
        traverse(original->left, cloned->left, target);
        traverse(original->right, cloned->right, target);
    }
};
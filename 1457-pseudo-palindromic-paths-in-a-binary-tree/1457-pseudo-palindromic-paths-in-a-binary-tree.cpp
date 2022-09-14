class Solution {
public:
    int count = 0;

    void preorder(TreeNode *node, int path) {
        if (!node)
            return;
        
        path = path ^ (1 << node->val);

        if (node->left == NULL && node->right == NULL) {
            if ((path & (path - 1)) == 0) {
                count++;
            }
        }
        preorder(node->left, path);
        preorder(node->right, path);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        preorder(root, 0);
        return count;
    }
};
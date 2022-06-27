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
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;
public:
    void recoverUntil(TreeNode* root)
    {
        if(root == nullptr)
            return;
        recoverUntil(root->left);
        if(prev != nullptr && prev->val > root->val)
        {
            if(first == nullptr)
                first = prev;
            second = root;
        }
        prev = root;
        recoverUntil(root->right);
    }
    void recoverTree(TreeNode* root) {

        recoverUntil(root);
        swap(first->val, second->val);
    }
};
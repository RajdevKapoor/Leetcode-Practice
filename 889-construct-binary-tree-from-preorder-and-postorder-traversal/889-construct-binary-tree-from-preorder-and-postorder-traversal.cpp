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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        vector<int> pos(pre.size()+1);
        for (int i = 0; i < post.size(); i++) pos[post[i]] = i;
        
        TreeNode* root = nullptr;
        int i = 0;
        root = build(root, pre, pos, i);
        
        return root;
    }
    
    TreeNode* build(TreeNode* root, vector<int>& pre, vector<int>& pos, int& i) {
        if (i < pre.size()) root = new TreeNode(pre[i]);
        if (i == pre.size() - 1) {
            i++;
            return root;
        }
        int local = i;
        if (i < pre.size() && pos[pre[local]] > pos[pre[i+1]]) 
            root->left = build(root->left, pre, pos, ++i);
        if (i < pre.size() && pos[pre[local]] > pos[pre[i+1]])
            root->right = build(root->right, pre, pos, ++i);

        return root;
    }
};
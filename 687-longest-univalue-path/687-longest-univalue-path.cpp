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
    int dfs(TreeNode *root, int &longestPath){
        if(root == nullptr) return 0;
        
        int leftPath  = dfs(root->left, longestPath);
        int rightPath = dfs(root->right, longestPath);
        
        if(root->left != nullptr  && root->left->val == root->val)
            leftPath += 1;
        
        else leftPath = 0;
        
        if(root->right != nullptr && root->right->val == root->val)
            rightPath += 1;
        
        else rightPath = 0; 
        
        longestPath = max(longestPath, leftPath + rightPath);
        
        return max(leftPath, rightPath);
    }
    
public:
    int longestUnivaluePath(TreeNode* root) {
        int longestPath = 0;
        
        dfs(root, longestPath);
        
        return longestPath;
    }
};
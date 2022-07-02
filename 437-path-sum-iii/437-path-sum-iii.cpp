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
public:
    int helper(TreeNode* root, int targetSum, long long current){
        if(!root) return 0;
        int ans = 0;
        if(current+root->val==targetSum) ans++;

        ans+= helper(root->left,targetSum,current+root->val);
        ans+= helper(root->right,targetSum,current+root->val);

        return ans;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        int ans = 0;

        ans+=helper(root,targetSum,0);

        ans+= pathSum(root->left,targetSum);
        ans+= pathSum(root->right,targetSum);

        return ans;
    }
};
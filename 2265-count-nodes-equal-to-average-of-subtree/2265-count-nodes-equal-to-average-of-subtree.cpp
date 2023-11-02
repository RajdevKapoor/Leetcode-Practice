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
    #define pii pair<int, int>
    int count;
public:
    
    pii solve(TreeNode* root){
        if(root==NULL){
            return {0,0};
        }
        
        pii l = solve(root->left);
        pii r = solve(root->right);
        
        int sum = l.first + r.first + root->val;
        int cnt = l.second + r.second + 1;
        
        if(root->val == (sum/cnt)) count++;
        
        return {sum,cnt};
    }
    
    int averageOfSubtree(TreeNode* root) {
        count = 0;
        solve(root);
        return count;
        
    }
};
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

#define pii pair<int,int>

class Solution {
public:
    pii solve(TreeNode* root) {
        
        if(root==NULL){
            return pii(0,0);
        }
        
        pii leftchild = solve(root->left);
        pii rightchild = solve(root->right);
        
        pii p;
        int wRobbery = root->val + (leftchild).second + (rightchild).second;
        int woRobbery = max(leftchild.first,leftchild.second)+ max(rightchild.first,rightchild.second);
        
        p.first=wRobbery;
        p.second=woRobbery;
        
        return p;
    }
    
    int rob(TreeNode* root) {
        
        pii p=solve(root);
        
        return max(p.first,p.second);
        
    }
};
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
    class pair{
    public:
        int f=-1;
        int b=-1;
        int msf=0;
    };

public:
    
    
    pair solve(TreeNode* root) {
        
        if(root==NULL){
            pair p;
            return p;
        }
        
        pair lchild = solve(root->left);
        pair rchild = solve(root->right);
        
        pair myans;
        myans.f = lchild.b+1;
        myans.b = rchild.f+1;
        myans.msf = max(max(rchild.msf,lchild.msf),max(myans.f,myans.b));
        
        return myans;
    }
    
    int longestZigZag(TreeNode* root) {
        
        pair ans = solve(root);
        
        return ans.msf;
    }
};
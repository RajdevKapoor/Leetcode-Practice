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
    TreeNode* solve(vector<int> in,vector<int> post ,int is,int ie ,int& p_index){
        if(is > ie)  return NULL;
        int index=0;
        TreeNode * root = new TreeNode(post[p_index--]);
        if(is == ie)
            return root;
        for(int i = is; i<=ie;i++){
            if(in[i] == root->val){
                index = i;
                break;
            }
        }
         root->right = solve(in,post,index+1,ie,p_index);
        root->left = solve(in,post,is,index-1,p_index);
       
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int is=0,ie = n-1;
        int p_index = n-1;
        return solve(inorder,postorder,is,ie,p_index);
    }
};
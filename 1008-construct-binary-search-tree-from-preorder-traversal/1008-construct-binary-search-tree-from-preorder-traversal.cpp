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
    int preindex = 0;
    TreeNode* solve(int is,int ie,vector<int>& preorder,vector<int>& inorder){
        if(is>ie){
            return NULL;
        }
        int index = 0;
        TreeNode *root = new TreeNode(preorder[preindex++]);

        for(int i=is;i<=ie;i++){
            if (inorder[i] == root->val){
                index = i;
                break;
            }
        }
        root->left = solve(is,index-1,preorder,inorder);
        root->right = solve(index+1,ie,preorder,inorder);
        return root;
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder;
        for(auto x:preorder){
            inorder.push_back(x);
        }
        sort(inorder.begin(),inorder.end());
        int n = preorder.size();
        return solve(0,n-1,preorder,inorder);
    }
    
    
};
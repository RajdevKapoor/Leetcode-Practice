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
    
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int &index, int start, int end){
        
        if(start>end){
            return NULL;
        }
        
        int x = preorder[index];
        TreeNode* root = new TreeNode(x);
        
        index++;
        
        if(start == end){
            return root;
        }else{
            int i=start;
            for(i=start; i<=end; i++)
            {
                if(inorder[i] == x)
                {
                    break;
                }
            }
            
            root->left = helper(preorder, inorder, index, start, i-1);
            root->right = helper(preorder, inorder, index, i+1, end);
            return root;
        }
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n = inorder.size();
        int start = 0;
        int end = n-1;
        int index = 0;
        return helper(preorder, inorder, index, start, end);
        
    }
};
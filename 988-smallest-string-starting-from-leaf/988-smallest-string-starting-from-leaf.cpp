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
    string ans = "";
    
public:
    void solve(TreeNode* root,string s) {
        if(root==NULL){
            return;
        }
        
        s+= root->val  + 'a';
        
        if(root->left==NULL and root->right==NULL){
            
            reverse(s.begin(),s.end());
            
            if(ans==""){
                ans=s;
            }else{
                ans=min(ans,s);
            }
        }
    
        
        solve(root->left,s);
        solve(root->right,s);
        
        
        
        

        
    }
    
    string smallestFromLeaf(TreeNode* root) {
        solve(root,"");
        return ans;
    }
};
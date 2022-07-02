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
    int ans;
public:
    int binaryToDecimal(string n)    {
        
        int dec_value = 0;
        int base = 1;
        int len = n.length();
        for (int i = len - 1; i >= 0; i--) {
            if (n[i] == '1')
                dec_value += base;
            base = base * 2;
        }

        return dec_value;
    }
    
    void solve(TreeNode* root,string s) {
        
        if(root==NULL){
            return;
        }
        
        s+=to_string(root->val);
        
        if(root->left==NULL and root->right==NULL){
            cout<<s<<endl;
            ans+=binaryToDecimal(s);
            return;
        }
        solve(root->left,s);
        solve(root->right,s);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        ans=0;
        solve(root,"");
        return ans;
    }
};
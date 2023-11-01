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
    void preorder(TreeNode* root, unordered_map <int,int> &mp){
        if(root==NULL){
            return;
        }
        
        mp[root->val]++;
        preorder(root->left,mp);
        preorder(root->right,mp);
    }
    
    vector<int> findMode(TreeNode* root) {
        unordered_map <int,int> mp;
        vector<int> ans;
        preorder(root,mp);
        
        int mx=0;
        for(auto m:mp){
            mx=max(mx,m.second);
        }
        
        for(auto m:mp){
            if(mx==m.second) ans.push_back(m.first);
        }
        return ans;
    }
};
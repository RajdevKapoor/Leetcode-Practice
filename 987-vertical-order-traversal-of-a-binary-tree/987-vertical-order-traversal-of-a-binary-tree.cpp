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
    void solve(TreeNode* root,int col,int row,map<pair<int,int>,vector<int>>& values){
        if(root==NULL) return ;
       
        values[{col,row}].push_back(root->val);
        solve(root->left,col-1,row+1,values);
        solve(root->right,col+1,row+1,values);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        map<pair<int,int>,vector<int>> values;
        solve(root,0,0,values);
        
        map<int,vector<int>> mp;
        for(auto a: values){
            int c= a.first.first;
            sort(a.second.begin(),a.second.end());
            for(auto v: a.second)
             mp[c].push_back(v);
        }
        for(auto b: mp){
            ans.push_back(b.second);
        }   
        return ans; 
        
    }
};
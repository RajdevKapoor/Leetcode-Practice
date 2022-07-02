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
     bool isCousins(TreeNode* root, int x, int y) {
        queue<pair<TreeNode*,TreeNode*>> q;
        map<int,int> mp;
        TreeNode* t = NULL;
        q.push({root,root});
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode* node = q.front().first;
                TreeNode* prev = q.front().second;
                q.pop();
                if(node->left) q.push({node->left,node});
                if(node->right) q.push({node->right,node});
                mp.insert({node->val,prev->val});
            }
            if(mp[x] && mp[y] && mp[x]!=mp[y] ){
                return true;
                break;
            }
            mp.clear();
        }
        return false;
    }
};
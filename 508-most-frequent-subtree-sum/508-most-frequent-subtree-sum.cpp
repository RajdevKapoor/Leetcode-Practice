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
    int mx_freq=0;
    unordered_map<int,int>map;
public:
    int dfs(TreeNode* root){
        if(root==NULL) return 0;
        
        int ls=dfs(root->left);
        int rs=dfs(root->right);
        int sum = root->val+ls+rs;
        
        map[sum]++;
        mx_freq=max(mx_freq,map[sum]);
            return sum;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        vector<int> ans;
        for(auto m:map){
            if(m.second==mx_freq) ans.push_back(m.first);
        }
        return ans;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs (TreeNode* root, TreeNode* parent, map <TreeNode*, TreeNode*> &mp){
        if (!root)
            return;
        
        if (root->left){
            mp[root->left] = root;
            dfs (root->left, root, mp);
        }
        
        if (root->right){
            mp[root->right] = root;
            dfs (root->right, root, mp);
        }
    }
    vector <int> ans;
    void getKDistNode (TreeNode* node, map <TreeNode*, TreeNode*> &mp, int cnt, int k, TreeNode* parent){
        if (!node)
            return;
        if (cnt == k){
            ans.push_back(node->val);
            return;
        }
        if (node->left != parent){
            getKDistNode (node->left, mp, cnt+1, k, node);
        }
        if (node->right != parent){
            getKDistNode (node->right, mp, cnt+1, k, node);
        }
        if (mp[node] != parent){
            getKDistNode (mp[node], mp, cnt+1, k, node);
        }
        return;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map <TreeNode*, TreeNode*> mp;
        
        mp[root] = NULL;
        
        dfs (root, NULL, mp);
        
        getKDistNode (target, mp, 0, k, NULL);
        return ans;
    }
};
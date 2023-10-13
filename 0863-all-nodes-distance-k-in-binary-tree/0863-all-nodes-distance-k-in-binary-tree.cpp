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
    map <TreeNode*, TreeNode*> mp;
    void dfs (TreeNode* root, TreeNode* parent){
        if (!root)
            return;
        
        if (root->left){
            mp[root->left] = root;
            dfs (root->left, root);
        }
        
        if (root->right){
            mp[root->right] = root;
            dfs (root->right, root);
        }
    }
    vector <int> ans;
    set<TreeNode*> vis;
    void getKDistNode (TreeNode* node, int cnt, int k){
        if (node==NULL){
            return;
        }
        
            
        if (cnt == k){
            ans.push_back(node->val);
            return;
        }
        
        vis.insert(node);
        
        if (vis.count(node->left)==0){
            getKDistNode (node->left, cnt+1, k);
        }
        
        if (vis.count(node->right)==0){
            getKDistNode (node->right,  cnt+1, k);
        }
        
        if (vis.count(mp[node])==0){
            getKDistNode (mp[node], cnt+1, k);
        }
        
        return;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        vis.insert(NULL);
        mp[root] = NULL;
        
        dfs (root, mp[root]);
        
        getKDistNode (target, 0, k);
        return ans;
    }
};
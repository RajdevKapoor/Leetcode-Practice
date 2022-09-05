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
    set<TreeNode*> vis;
    void getKDistNode (TreeNode* node, map <TreeNode*, TreeNode*> &mp, int cnt, int k, TreeNode* parent){
        if (node==NULL){
            return;
        }
        
            
        if (cnt == k){
            ans.push_back(node->val);
            return;
        }
        
        vis.insert(node);
        
        if (vis.count(node->left)==0){
            getKDistNode (node->left, mp, cnt+1, k, node);
        }
        
        if (vis.count(node->right)==0){
            getKDistNode (node->right, mp, cnt+1, k, node);
        }
        
        if (vis.count(mp[node])==0){
            getKDistNode (mp[node], mp, cnt+1, k, node);
        }
        
        return;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        map <TreeNode*, TreeNode*> mp;
        vis.insert(NULL);
        mp[root] = NULL;
        
        dfs (root, mp[root], mp);
        
        getKDistNode (target, mp, 0, k, NULL);
        return ans;
    }
};
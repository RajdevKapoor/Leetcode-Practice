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
    void helper(TreeNode* root, TreeNode* parent, unordered_map<TreeNode*, TreeNode*>& m, vector<TreeNode*>& leafNode)
    {
        if(root == NULL)
            return;
        if(root->left == NULL && root->right == NULL)
        {
            leafNode.push_back(root);
        }
        m[root] = parent;
        helper(root->left,root,m,leafNode);
        helper(root->right,root,m,leafNode);
    }
    
    int countPairs(TreeNode* root, int distance) {
        
        unordered_map<TreeNode*, TreeNode*> m;
        vector<TreeNode*> leafNode;
        helper(root,NULL, m ,leafNode);
        
        int ans = 0;
        for(int i = 0; i<leafNode.size(); i++)
        {
            unordered_map<TreeNode*, bool> visited;
            queue<TreeNode*> q;
            q.push(leafNode[i]);
            visited[leafNode[i]] = true;
            int count = 0;
            while(!q.empty())
            {
                int n = q.size();
                for(int j = 0; j<n; j++)
                {
                    TreeNode* f = q.front();
                    q.pop();
                    
                    if(f->left == NULL && f->right == NULL && f!=leafNode[i]) ans++;
                    
                    if(f->left && !visited.count(f->left))
                    {
                        visited[f->left] = true;
                        q.push(f->left);
                    }
                    if(f->right && !visited.count(f->right))
                    {
                        visited[f->right] = true;
                        q.push(f->right);
                    }
                    if(m[f]!= NULL && !visited.count(m[f]))
                    {
                        visited[m[f]] = true;
                        q.push(m[f]);
                    }
                }
                count++;
                if(count > distance)
                {
                    break;
                }
            }
        }
        return ans/2;
        
    }
};
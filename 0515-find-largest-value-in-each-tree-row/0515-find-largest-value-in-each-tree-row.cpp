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
    vector<int> largestValues(TreeNode* root) {
        
        vector<int> res;
        
        if(root==NULL) return res;
        
        queue<TreeNode* >q;
        q.push(root);
        
        while(q.size()){
            
            int ans=INT_MIN;
            int size =q.size();
            
            for(int i=0;i<size;i++){
                auto tmp =q.front();
                q.pop();
                
                if(tmp->left){
                    q.push(tmp->left);
                    
                }
                if(tmp->right){
                    q.push(tmp->right);
                }
                
                ans=max(ans,tmp->val);
            }
            
            res.push_back(ans);
        }
        return res;
    }
};
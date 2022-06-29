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
    bool getRootToNodePath(TreeNode* root,TreeNode* target,vector<TreeNode*> &v){
        if(root==NULL) return false;
        
        if(root==target){
            v.push_back(root);
            return true;
        }
        
        bool left = getRootToNodePath(root->left,target,v);
        
        if(left){
           v.push_back(root);
            return true; 
        }
        
        bool right = getRootToNodePath(root->right,target,v);
        
        if(right){
           v.push_back(root);
            return true; 
        }
        
        return false;
        
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        vector<TreeNode*> findp, findq;
        getRootToNodePath(root,p,findp);
        getRootToNodePath(root,q,findq);
        
        int i=0;
        
        reverse(findp.begin(),findp.end());
        reverse(findq.begin(),findq.end());
        
        while(i<min(findp.size(),findq.size()) and findp[i]==findq[i]) i++;
        
        return findp[i-1];
        
        
    }
};
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
private:
    map<TreeNode* ,TreeNode* > parentOf;
public:
    
    void getParent(TreeNode* root){
        if(root==NULL) return;
        
        if(root->left){
            parentOf[root->left]=root;
            getParent(root->left);
        }
        
        if(root->right){
            parentOf[root->right]=root;
            getParent(root->right);
        }
        
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        parentOf[root]=NULL;
        getParent(root);
        
        set<TreeNode*> vis;
        
        queue<pair<TreeNode*,int>> q;
        
        vector<int> ans;
        
        q.push({target,0});
        vis.insert(target);
        
        while(q.size()){
            
            int sz = q.size();
            
            for(int i=0;i<sz;i++){
                
                auto f = q.front(); q.pop();
                
                auto node = f.first;
                auto level = f.second;
                
                if(level==k){
                    ans.push_back(node->val);
                }
                vis.insert(node);
                //left
                if(level>k){
                    continue;
                }
                
                if(node->left and vis.count(node->left)==0){
                    q.push({node->left,level+1});
                }
                
                if(node->right and vis.count(node->right)==0){
                    q.push({node->right,level+1});
                }
                
                if(parentOf[node] and vis.count(parentOf[node])==0){
                    q.push({parentOf[node],level+1});
                }
                
            }
            
        }
        
        return ans;
    }
};
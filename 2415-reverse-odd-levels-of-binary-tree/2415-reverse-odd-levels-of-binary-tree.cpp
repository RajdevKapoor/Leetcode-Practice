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
    TreeNode* reverseOddLevels(TreeNode* root) {
        
        if(root==NULL) return root;
        
        queue <TreeNode*> q;
        q.push(root);
        
        int level=0;
        while(q.size()){
            int size = q.size();
            vector<TreeNode*> v;
            for(int i=0;i<size;i++){
                if(q.front()->left){
                    q.push(q.front()->left);
                }
                if(q.front()->right){
                    q.push(q.front()->right);
                }
                
                v.push_back(q.front());
                q.pop();
                
                
            }
            if(level&1){
                
                int i=0,j=v.size()-1;
                while(i<j){
                    swap(v[i++]->val,v[j--]->val);
                }
                
            }           
            // ans.push_back(v);
            level++;
        }
        
        return root;
        
    }
};
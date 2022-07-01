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
#define pii pair<int,int>
class Solution {
public:
      
    int widthOfBinaryTree(TreeNode* root) {
        int ans=0;
        if(root==NULL)return ans;
        
        queue<pair<TreeNode *, long long >> q;
        q.push({root, 0});
        
        while(q.size()){
            int sz = q.size();
            int levelmini=q.front().second; 
            int first,last;
            for(int i=0;i<sz;i++){
                auto tmp = q.front().first;
                auto id = q.front().second-levelmini;
                
                q.pop();
                
                if(i==0){
                    first = id;
                }
                if(i==sz-1){
                    last = id;
                }
                
                if(tmp->left){
                    q.push({tmp->left,2*id+1});
                }
                if(tmp->right){
                    q.push({tmp->right,2*id+2});
                }
            }
            
            ans=max(ans,last-first+1);
        }
        
        return ans;
    }
};
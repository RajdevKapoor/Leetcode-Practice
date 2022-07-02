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
    vector<int> ans;
public:
    bool solve(TreeNode* root, vector<int>& voyage,int &i) {
        if(root==NULL){
            return true;
        }
        
        if(root->val != voyage[i]){
            return false;
        }
        
        i++;
        
        if(i<voyage.size() and root->left and root->left->val!=voyage[i]){
            auto temp = root->left;
            root->left=root->right;
            root->right=temp;
            
            if(root->left and root->left->val!=voyage[i]){
                return false;
            }
            
            ans.push_back(root->val);
        }
        
        return solve(root->left,voyage,i)and solve(root->right,voyage,i);
    }
    
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        int i=0;
        bool check = solve(root,voyage,i);
        
        if(!check) return {-1};
        return ans;
    }
};
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
    
    int maxi(vector<int>& nums,int start,int end) {
        int max_i = start;
        for (int i = start; i <end; i++) {
            if (nums[max_i] < nums[i])
                max_i = i;
        }
        return max_i;
    }
    
    TreeNode* solve(vector<int>& nums,int start,int end){
        
        if(start>=end) return NULL;
        
        int mid=maxi(nums,start,end);
        
        TreeNode* root = new TreeNode(nums[mid]);
        root->left=solve(nums,start,mid);
        root->right=solve(nums,mid+1,end);
        
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size()==0){
            return NULL;
        }
        int start=0;
        int end=nums.size();
        return solve(nums,0,end);
        
    }
};
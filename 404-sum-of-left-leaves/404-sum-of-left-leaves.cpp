class Solution {
public:
     int sum = 0;
     int sumOfLeftLeaves(TreeNode* root) {
         if(root->left){
             sumOfLeftLeaves(root->left);
             if(!root->left->left && !root->left->right) sum+=root->left->val;
         }
         if(root->right) sumOfLeftLeaves(root->right);
         return sum;
     }
};
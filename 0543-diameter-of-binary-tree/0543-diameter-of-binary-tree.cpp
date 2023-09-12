class Solution {
    int daimeter=0;
public:
    int findHeightOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        
        int left_height = findHeightOfBinaryTree(root->left);
        int right_height = findHeightOfBinaryTree(root->right);
        
        daimeter = max(daimeter, left_height+right_height);
        
        return max(left_height, right_height) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        findHeightOfBinaryTree(root);
        return daimeter;
    }
};
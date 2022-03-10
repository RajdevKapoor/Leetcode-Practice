class Solution {
public:
    bool  ans = true;
    int checkBalance(TreeNode* root){
        if(root == NULL)
            return 0;

        int leftSubTree = checkBalance(root->left);
        int rightSubTree = checkBalance(root->right);
        if(abs(leftSubTree-rightSubTree) > 1){
            ans = false;
        }
        return 1 + max(leftSubTree, rightSubTree);
    }
    bool isBalanced(TreeNode* root){
        checkBalance(root);
        return ans;
    }
};
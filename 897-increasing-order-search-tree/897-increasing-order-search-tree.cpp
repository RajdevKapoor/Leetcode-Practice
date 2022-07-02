class Solution {
public:
    void inorder(TreeNode* root,vector<int>&in){
        if(root==NULL){
            return;
        }
        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int>in;
        inorder(root,in);
        TreeNode* curr=new TreeNode(in[0]);
        TreeNode* par=curr;
        for(int i=1;i<in.size();i++){
            
            par->right=new TreeNode(in[i]);
            par->left=NULL;
            par= par->right;
            
        }
        return curr;
    }
};
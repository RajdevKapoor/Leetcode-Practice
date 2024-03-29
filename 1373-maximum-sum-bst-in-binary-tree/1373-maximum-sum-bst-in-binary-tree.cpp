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

 // {{isBst,{max_val,min_val}},BST_sum}
 #define pr pair<pair<bool,pair<int,int>>,int>
int ans;
class Solution {
    pr solve(TreeNode* root){
        if(root == NULL){
            //empty tree is a BST
            //since we need to make comparisons, setting max value as INT_MIN and min value as INT_MAX
            return {{true,{INT_MIN,INT_MAX}},0};
        }

        //traversal
        pr leftT = solve(root -> left);
        pr rightT = solve(root -> right);
        
        //fetching values from the pair, variable names are justified
        int maxSumLeft = leftT.second;
        int maxSumRight = rightT.second;
        bool isLeftBST = leftT.first.first;
        bool isRightBST = rightT.first.first;
        int leftTreeMax = leftT.first.second.first;
        int leftTreeMin = leftT.first.second.second;
        int rightTreeMin = rightT.first.second.second;
        int rightTreeMax = rightT.first.second.first;
        
        //if the tree is BST then the maximum value in the tree will be the maximum value in right tree
        //since the right tree or left tree might be empty so we are comparing it with root value
        int treeMax = max(root->val,rightTreeMax);
        int treeMin = min(root->val,leftTreeMin);

        //check all conditions for BST
        if(isLeftBST && isRightBST && root -> val < rightTreeMin && root -> val > leftTreeMax){
            //whole Tree is BST
            
            //getting sum of BST
            int sum = root->val+maxSumLeft+maxSumRight;

            //updating the ans variable with all possibilities
            //dry run the code if you dont understand why we are taking all possible values
            ans = max({ans,maxSumLeft,maxSumRight,sum});
            return {{true,{treeMax,treeMin}},sum};
        }
        // it is not a BST
        // since it is not a BST so we will return max sum so generated as we are making comparisions in the function at each node
        int sum = max(maxSumLeft,maxSumRight);
        ans = max(ans,sum);
        return {{false,{treeMax,treeMin}},sum};
    }
public:
    int maxSumBST(TreeNode* root) {
        ans = 0;
        solve(root);
        return ans;
    }
};
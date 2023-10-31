// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// private:
//     unordered_map<TreeNode*,TreeNode*> parentOf;
//     TreeNode* start;
//     TreeNode* dest;
    
// public:
//     void getParent(TreeNode* root){
        
//         if(root==NULL) return;
        
//         if(root->left){
//             parentOf[root->left]=root;
//         }
//         if(root->right){
//             parentOf[root->right]=root;
//         }
        
//         getParent(root->left);
//         getParent(root->right);
        
//     }
    
//     void getStartEnd(TreeNode* root,int startValue, int destValue){
//         if(root==NULL){
//             return;
//         }
        
//         if(root->val == startValue){
//             start = root;
//         }
        
//         if(root->val == destValue){
//             dest=root;
//         }
        
//         if(start and dest){
//             return;
//         }
        
//         getStartEnd(root->left,startValue,destValue);
//         getStartEnd(root->right,startValue,destValue);
        
//         return;
//     }
    
//     string getDirections(TreeNode* root, int startValue, int destValue) {
        
//         parentOf[root]=NULL;
//         getParent(root);
        
//         getStartEnd(root,startValue,destValue);
        
//         string ans="";
//         queue<pair<TreeNode*,string>> q;
//         q.push({start,""});
//         set<TreeNode*> vis;
//         vis.insert(start);
//         while(q.size()){
//             int sz = q.size();
//             for(int i=0;i<sz;i++){
//                 auto parent = q.front();
//                 q.pop();
                
//                 auto node = parent.first;
//                 auto ans = parent.second;
                
//                 if(node==dest){
//                     return ans;
//                 }
                
//                 if(node->left and vis.count(node->left)==0){
//                     q.push({node->left,ans+"L"});
//                     vis.insert(node->left);
//                 }
                
//                 if(node->right and vis.count(node->right)==0){
//                     q.push({node->right,ans+"R"});
//                     vis.insert(node->right);
//                 }
                
//                 if(parentOf.count(node) and parentOf[node]!=NULL and vis.count(parentOf[node])==0){
//                     q.push({parentOf[node],ans+"U"});
//                     vis.insert(parentOf[node]);
//                 }
//             }
//         }
//         return ans;
//     }
// };



class Solution {
    string res;
public:
    void solve(TreeNode* node,TreeNode* dst,string &ans,unordered_map<TreeNode*,TreeNode*>&par){
           if(node==NULL) return;
           if(node==dst){
               res=ans;
               return ;
           }
           int mark=node->val;
           node->val=-1;
          if(node->left && node->left->val!=-1){
              ans+='L';
              solve(node->left,dst,ans,par);
          }
          if(node->right && node->right->val!=-1){
              ans+='R';
              solve(node->right,dst,ans,par);
          }
          if(par[node] && par[node]->val!=-1){
              ans+='U';
              solve(par[node],dst,ans,par);
          }
          node->val=mark;
          ans.pop_back();
        
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        unordered_map<TreeNode*,TreeNode*>par;//node par
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* start=NULL;
        TreeNode* dst=NULL;
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left){
                    par[node->left]=node;
                    q.push(node->left);
                }
                if(node->right){
                    par[node->right]=node;
                    q.push(node->right);
                }
                if(node->val==startValue){
                    start=node;
                }
                if(node->val==destValue){
                    dst=node;
                }
            }
        }

        string ans="";
        solve(start,dst,ans,par);
        return res;
    }
};

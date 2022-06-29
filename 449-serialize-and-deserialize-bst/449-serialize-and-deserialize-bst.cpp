/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    
    void preorder(TreeNode* root,string &s) {
        
        if(root==NULL){
            s+="#";
            s+=".";
            return;
        }
        s+=to_string(root->val);
        s+=".";
        
        preorder(root->left,s);
        preorder(root->right,s);
        
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        preorder(root,s);
        return s;
    }
    
    
    TreeNode* preordereReverse(string s,int &i){
        
        string key="";
        for(;i<s.size();i++){
            if(s[i]=='.') break;
            key+=s[i];
        }
        i++;
        
        if(key=="#") return NULL;
        
        TreeNode* root = new TreeNode(stoi(key));
        root->left = preordereReverse(s,i);
        root->right = preordereReverse(s,i);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        int i=0;
        return preordereReverse(data,i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
class Solution {
public:
    vector<string> ans;
    
    void helper(int o, int c, string s, int n){
        
        if(o== n and c==n){
            ans.push_back(s);
        }
        
        if(o<n){
            helper(o+1,c,s+"(",n);
        }
        
        if(c<n and c<o){
             helper(o,c+1,s+")",n);
        }
        
        
    }
    
    vector<string> generateParenthesis(int n) {
        string s="";
        helper(0,0,s,n);
            
        return ans;
    }
};
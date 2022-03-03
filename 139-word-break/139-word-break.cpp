class Solution {
public:
    int solve(int idx,string &str,unordered_set<string> &st,vector<int> &dp){
        if(idx >= str.size()) return true;
        else if(dp[idx] != -1) return dp[idx];
        
        for(int i=1;i<str.size()-idx+1;i++){
            // fp - first part, sp - second part
            string fp = str.substr(idx,i);
            if(st.find(fp) != st.end()){
                int sp = solve(idx+i,str,st,dp);
                if(sp) return dp[idx] = true;
            }
        }
        
        return dp[idx] = false;
    }    
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> st;
        for(auto &it : wordDict) st.insert(it);
        vector<int> dp(n,-1);
        return solve(0,s,st,dp);        
    }
};
class Solution {
public:
    int dp[301];
    int help(int i,string &s, set<string> wordDist){
        
        if(i == s.size()) return 1;
        
        string temp;
        
        if(dp[i]!=-1)return dp[i];
        
        for(int j = i; j<s.size();j++){
            temp+=s[j];
            if(wordDist.find(temp)!=wordDist.end())
                if(help(j+1,s,wordDist)) return dp[i] = 1;
            
        }
        
        return dp[i] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp,-1,sizeof dp);
        set<string>st;
        
        for(auto i:wordDict) st.insert(i);
        return help(0,s,st);
        
    }
};
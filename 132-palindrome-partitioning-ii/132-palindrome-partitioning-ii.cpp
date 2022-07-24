class Solution {
private:
    bool isPalindrome(string &s, int start, int end) {
        while (start <= end) {
          if (s[start++] != s[end--])
            return false;
        }
        return true;
      }
    
public:
    int solve(int partition, string &s, vector<int> &dp){
        
        if(partition==s.size()){
            return -1;
        }
        if(dp[partition]!=-1) return dp[partition];
        
        int ans = INT_MAX;
        
        for(int i=partition;i<s.size();i++){
            
            if(isPalindrome(s,partition,i)){
                int cost = 1+solve(i+1,s,dp);
                ans=min(ans,cost);
            }
            
        }
        
        return dp[partition]=ans;
        
    }
    
    int minCut(string s) {
        vector<int> dp(s.length(),-1);
        
        return solve(0,s,dp);
        
    }
};
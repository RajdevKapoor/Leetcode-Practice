class Solution {
public:
    
    int getdifficulty(int pos , vector<int> &jobs , int d , vector<vector<int>> &dp){
        
       int n = jobs.size();
        
       if(d == 1){
           int mx = INT_MIN;
           for(int i=pos ; i<n ; ++i) mx = max(mx,jobs[i]);
           return mx;
       } 
        
       if(dp[pos][d] != -1) return dp[pos][d]; 
        
       int ans = INT_MAX;
       int mx = jobs[pos];
       for(int i=pos+1 ; i<=n-d+1 ; ++i){
           
           ans = min(ans,mx + getdifficulty(i,jobs,d-1,dp));
           mx = max(mx,jobs[i]);
           
       } 
       return dp[pos][d] = ans; 
    }

    int minDifficulty(vector<int>& jobs, int d) {
        int n = jobs.size();
        if(d > n) return -1;
        vector<vector<int>> dp(n+1,vector<int>(d+1,-1));
        return getdifficulty(0,jobs,d,dp);
    } 
};
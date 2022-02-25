class Solution {
public:
    
    int solve(string &s1,int n, string &s2,int m,int i,int j,vector<vector<int>> &dp){
        
        if(i==n or j==m) return 0;
        
        if(dp[i][j]!=-1){
            return dp[i][j] ;
        }
        
        if(s1[i]==s2[j]){
            return dp[i][j] = 1+solve(s1,n,s2,m,i+1,j+1,dp);
        }
        else{
            int op1 = solve(s1,n,s2,m,i+1,j,dp);
            int op2 = solve(s1,n,s2,m,i,j+1,dp);
            return dp[i][j] = max(op1,op2);
        }
        
        
    }
    
    
    int longestCommonSubsequence(string s1, string s2) {
        
        int n=s1.length();
        int m=s2.length();
        
        vector<vector<int>> dp(n,vector <int>(m,-1));
        
        return solve(s1,n,s2,m,0,0,dp);
        
    }
};
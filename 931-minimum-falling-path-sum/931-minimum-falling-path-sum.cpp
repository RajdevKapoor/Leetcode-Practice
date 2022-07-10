class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        
        
        
        if(i<0 or i>=matrix.size() or j<0 or j>=matrix[0].size()) return 1e8;
        
        if(i==0) return matrix[i][j];
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int up = matrix[i][j] + solve(i-1,j,matrix,dp);
        int upLeft = matrix[i][j] + solve(i-1,j-1,matrix,dp);
        int upRight = matrix[i][j] + solve(i-1,j+1,matrix,dp);
        
        return dp[i][j]=min(up,min(upLeft,upRight));
        
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans=INT_MAX;
        for(int j=0;j<m;j++){
            ans=min(ans,solve(n-1,j,matrix,dp));
        }
        
        
        
        
        return ans;
    }
};
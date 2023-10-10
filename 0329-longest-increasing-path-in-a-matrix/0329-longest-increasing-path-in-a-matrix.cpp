class Solution {
    
public:
    
    int solve(vector<vector<int>>& matrix,vector<vector<int>>& dp,int i, int j, int n, int m, int &ans){
        
        if(i<0 or i>=n or j<0 or j>=m){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int op1 =0, op2=0, op3=0, op4=0;
        
        if(i+1<n and matrix[i][j]<matrix[i+1][j]){
             op1 = 1 +  solve(matrix,dp,i+1,j,n,m,ans);
        }
        
        if(i-1>=0 and matrix[i][j]<matrix[i-1][j]){
             op2 = 1 +  solve(matrix,dp,i-1,j,n,m,ans);
        }
        
        if(j+1<m and matrix[i][j]<matrix[i][j+1]){
             op3 = 1 +  solve(matrix,dp,i,j+1,n,m,ans);
        }
        
        if(j-1>=0 and matrix[i][j]<matrix[i][j-1]){
             op4 = 1 +  solve(matrix,dp,i,j-1,n,m,ans);
        }
        dp[i][j] = max(op1,max(op2,max(op3,op4))); 
        
        ans = max(ans,dp[i][j]);
        
        
        return dp[i][j];
        
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        int ans = 0;
        
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                solve(matrix,dp,i,j,n,m,ans);
            }
        }
        
        
        return ans+1;
        
    }
};
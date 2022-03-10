class Solution {
public:
    
    
    
    int solve(vector<vector<int>>& grid,int i,int j, int m,int n,vector<vector<int>> &dp){
        
        if(i>=m or j>=n){
            return INT_MAX;            
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(i==m-1 and j==n-1){
            return grid[i][j];
        }
              
        
        int right = solve(grid,i+1,j,m,n,dp);
        int down = solve(grid,i,j+1,m,n,dp);
        
        int ans = grid[i][j] + min(right,down);
        
        
        dp[i][j]=ans;
        return ans;
        
    }
    
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n= grid[0].size();
        int i=0,j=0;
        vector<vector<int> > dp( m+1 , vector<int> (n+1, -1));
        return solve(grid,i,j,m,n,dp);
        
        
    }
};
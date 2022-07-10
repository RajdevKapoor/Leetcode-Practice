class Solution {
public:
    int util(int i, int j, vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(j<0 || j>=grid[0].size()){
            return 1e8;
        }
        if(i==0){
            return grid[0][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int ans=INT_MAX;
        
        for(int x=0;x<grid[0].size();x++){
            if(x!=j){
                ans=min(ans,grid[i][j]+util(i-1,x,grid,dp));
            }
        }
        return dp[i][j] = ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int ans = 1e8;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<m;i++){
            ans = min(ans,util(n-1,i,grid,dp));
        }
        return ans;
    }
};
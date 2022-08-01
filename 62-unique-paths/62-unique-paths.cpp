class Solution {
public:
    int solve(vector<vector<int>> &dp, int m,int n,int i, int j){
        if(i<0 or i>=m or j<0 or j>=n) return 0;
        
        if(i==m-1 and j==n-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int d =solve(dp,m,n,i+1,j);
        int r = solve(dp,m,n,i,j+1);
        
        return dp[i][j]=r+d;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                dp[i][j]=dp[i+1][j]+dp[i][j+1];
            }
        }
        
        return dp[0][0];
    }
};
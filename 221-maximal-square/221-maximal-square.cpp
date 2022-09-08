class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        vector<vector<int>> dp(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i][j]=matrix[i][j]-'0';
                
                ans=max(ans,dp[i][j]);
            }
        }
        
        
        
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                
                if(dp[i][j]==0) continue;
                
                dp[i][j]=min(dp[i+1][j],min(dp[i+1][j+1],dp[i][j+1]))+1;
                ans=max(ans,dp[i][j]);
            }
        }
        
        return ans*ans;
        
        
    }
};
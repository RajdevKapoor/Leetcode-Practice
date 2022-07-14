class Solution {
public:
    int minInsertions(string s) {
        
        vector<vector<int>> dp(s.length()+1,vector<int>(s.length()+1,-1));
        
        string t=s;
        reverse(begin(t),end(t));
        
        
        int n=s.length();
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
            dp[0][i]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return n-dp[n][n];
        
    }
};
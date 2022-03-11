class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        
        if (n==1){
            return 1;
        }
        int dp[n][n];
        int count=0;
        
        for(int g=0; g<n;g++){
            for(int i=0, j=g; j<n;i++,j++){
                
                if(g==0){
                    dp[i][j]=1;
                     count++;
                }else if(g==1){
                     if( s[i]==s[j]){
                        dp[i][j] = 1;
                         count++;
                    }else{
                        dp[i][j] = 0;
                    } 
                }else{
                    if(s[i]==s[j] and dp[i+1][j-1] == 1 ) {
                        dp[i][j] = 1;
                         count++;
                    }else{
                        dp[i][j] = 0;
                    } 
                }
                
            }
        }
        return count;
        
    }
};
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        string ans="";
        if (n==1){
            return s;
        }
        
        if (n==2){
            if( s[0]==s[1]){
               return s;
            }else{
             ans= s[0];
                return ans;
         } 
        }
        
        
        int dp[n][n];
        
        int l,r;
      
       
        for(int g=0; g<n;g++){
            for(int i=0, j=g; j<n;i++,j++){
                
                if(g==0){
                    dp[i][j]=1;
                     l=i;r=g;
                    
                }else if(g==1){
                     if( s[i]==s[j]){
                        dp[i][j] = 1;
                         l=i;r=g;
                         
                    }else{
                        dp[i][j] = 0;
                    } 
                }else{
                    if(s[i]==s[j] and dp[i+1][j-1] == 1 ) {
                        dp[i][j] = 1;
                        l=i;r=g;
                    }else{
                        dp[i][j] = 0;
                    } 
                }
                
            }
        }
        ans= s.substr(l,r+1);
        return ans;
    }
};
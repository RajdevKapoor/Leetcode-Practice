class Solution {
public:
    int climbStairs(int n) {
        
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        
        for(int i=2;i<=n;i++){
            
            int op1 =  dp[i-1];
            int op2 =  dp[i-2];
            
            dp[i]=op1+op2;
            
        }
        
        return dp[n];
    }
};
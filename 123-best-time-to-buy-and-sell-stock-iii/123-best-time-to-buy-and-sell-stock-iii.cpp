class Solution {
public:
    int solve(int i,vector<int>& prices,int buy,vector<vector<vector<int>>> &dp,int cap){
        
        if(i==prices.size() or cap==0) return 0;
        
        int profit=0;
        
        if(dp[i][buy][cap]!=-1) return  dp[i][buy][cap];
        
        if(buy){
            
            int op1 = -prices[i] + solve(i+1,prices,0,dp,cap);
            int op2 = solve(i+1,prices,1,dp,cap);
            profit=max(op1,op2);
            
        }else{
            
            int op1 = prices[i] + solve(i+1,prices,1,dp,cap-1);
            int op2 = solve(i+1,prices,0,dp,cap);
            profit=max(op1,op2);
            
        }
        
        
        return dp[i][buy][cap]=profit;      
        
        
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),
                                      vector<vector<int>>(2,vector<int>(3,-1)));
        
        
        return solve(0,prices,1,dp,2);
    }
};
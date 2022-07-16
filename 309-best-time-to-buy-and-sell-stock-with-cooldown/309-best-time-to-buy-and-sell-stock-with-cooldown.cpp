class Solution {
public:
    int solve(int i,vector<int>& prices,int buy,vector<vector<int>> &dp){
        
        if(i>=prices.size()) return 0;
        
        int profit=0;
        
        if(dp[i][buy]!=-1) return  dp[i][buy];
        
        if(buy){
            
            int op1 = -prices[i] + solve(i+1,prices,0,dp);
            int op2 = solve(i+1,prices,1,dp);
            profit=max(op1,op2);
            
        }else{
            
            int op1 = prices[i] + solve(i+2,prices,1,dp);
            int op2 = solve(i+1,prices,0,dp);
            profit=max(op1,op2);
            
        }
        
        
        return dp[i][buy]=profit;      
        
        
    }
    
    int maxProfit(vector<int>& prices) {
        
        
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        solve(0,prices,1,dp);
        
        return dp[0][1];
    }
   
};
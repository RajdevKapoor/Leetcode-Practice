class Solution {
public:
    int f;
    int solve(int i,vector<int>& prices,int buy,vector<vector<int>> &dp){
        
        if(i==prices.size()) return 0;
        
        int profit=0;
        
        if(dp[i][buy]!=-1) return  dp[i][buy];
        
        if(buy){
            
            int op1 = -prices[i] + solve(i+1,prices,0,dp);
            int op2 = solve(i+1,prices,1,dp);
            profit=max(op1,op2);
            
        }else{
            
            int op1 = prices[i] + solve(i+1,prices,1,dp)-f;
            int op2 = solve(i+1,prices,0,dp);
            profit=max(op1,op2);
            
        }
        
        
        return dp[i][buy]=profit;      
        
        
    }
    
    int maxProfit(vector<int>& prices,int fee) {
        
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,0));
        int n=prices.size();
        for(int i=n-1;i>=0;i--){
            for(int buy=1;buy>=0;buy--){
                
                int profit=0;
                
                if(buy){
            
                    int op1 = -prices[i] + dp[i+1][0];
                    int op2 = dp[i+1][1];
                    profit=max(op1,op2);

                }else{
            
                    int op1 = prices[i]-fee + dp[i+1][1];
                    int op2 = dp[i+1][0];
                    profit=max(op1,op2);

                }  
                
                dp[i][buy]=profit;
            }
        }
        
        
        return dp[0][1];
    }
   
};
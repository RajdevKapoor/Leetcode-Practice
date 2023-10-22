class Solution {
public:
    int solve(int i, vector<int>& cost,vector<int>& dp){
        if(i>=cost.size()) return 0;
        
        if(dp[i]!=-1) return dp[i];
        
        int op1 = cost[i]+ solve(i+1,cost,dp);
        int op2 = cost[i]+ solve(i+2,cost,dp);
        
        return dp[i]=min(op1,op2);
        
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        
        
        
        
        vector<int> dp(cost.size(),-1);
        
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        for(int i=2;i<cost.size();i++){
            dp[i] = min(cost[i]+dp[i-1],cost[i]+dp[i-2]);
        }
        
        
        return min(dp[cost.size()-1],dp[cost.size()-2]);
        
        
    }
};
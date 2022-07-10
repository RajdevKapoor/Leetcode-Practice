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
        solve(0,cost,dp);
        return min(dp[0],dp[1]);
        
        
    }
};
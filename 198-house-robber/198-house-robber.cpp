class Solution {
private:
    
public:
    int solve(vector<int>& nums,int i,vector<int> &dp){
        
        if(i<0) return 0;
        
        if(dp[i]!=-1) return dp[i];
        
        int pick = nums[i]+solve(nums,i-2,dp);
        int notpick = solve(nums,i-1,dp);
        
        return dp[i]=max(pick,notpick);
        
    }
    
    int rob(vector<int>& nums) {
        vector<int> dp(101,-1);
        return solve(nums,nums.size()-1,dp);
    }
};
class Solution {
public:
    bool solve(vector<int>& nums,int target,int i,vector<vector<int>>& dp){
        
        if(target==0) return true;
        
        if(i==nums.size()) return target==0;
        
        
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        
        bool not_take = solve(nums,target,i+1,dp);
        
        bool take = false;
        
        if(nums[i]<=target){
            take = solve(nums,target-nums[i],i+1,dp);
        }
        
        return dp[i][target] = not_take or take;
        
    }
    
    bool canPartition(vector<int>& nums) {
        
        int sum=0;
        
        for(int n:nums){
            sum+=n;
        }
        
        if(sum&1) return false;
        vector<vector<int>> dp(nums.size(), vector<int>(sum/2+1,-1));
        return solve(nums,sum/2,0,dp);
        
    }
};
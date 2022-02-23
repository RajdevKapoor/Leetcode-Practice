class Solution {
public:
    int solve(vector<int>& nums,int n, vector<int>& dp, int i){
        
        if(i==n-1){
            return 0;
        }
        
        if(i>=n){
            return INT_MAX;
        }
        
        if(dp[i]){
            return dp[i];
        }
        
        int ans= INT_MAX;
        int jumps = nums[i];
        
        for(int j=1;j<=jumps;j++){
            
            int nextStep=i+j;
            int furtherRecquired = solve(nums,n,dp,nextStep);
            
            if(furtherRecquired != INT_MAX){
                ans=min(ans,furtherRecquired+1);
            }
            
            
        }
        
        dp[i]=ans;
        
        return dp[i];
        
    }
    
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);
        return solve(nums,n,dp,0);
        
    }
};
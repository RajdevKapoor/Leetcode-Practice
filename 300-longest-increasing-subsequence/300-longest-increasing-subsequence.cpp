class Solution {
public:
    
    int f(int i, int prev, vector<int>& nums,vector<vector<int>> &dp){
        
        if(i==nums.size()) return 0;
        
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        
        int len = 0;
        len = f(i+1,prev,nums,dp);
        
        if(prev==-1 or nums[prev]<nums[i]){
            len = max(len,1+f(i+1,i,nums,dp));
        }
        
        return dp[i][prev+1]=len;
        
    }
    
    int lengthOfLIS(vector<int>& nums) {
        
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        
        return f(0,-1,nums,dp);
       
    }
};
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
        
        vector<int> dp(n,1);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i;j>=0;j--){
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            
            ans=max(ans,dp[i]);
        }
        
        return ans;
       
    }
};
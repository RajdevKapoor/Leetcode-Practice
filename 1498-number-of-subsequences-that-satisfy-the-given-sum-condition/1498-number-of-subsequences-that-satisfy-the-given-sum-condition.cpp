class Solution {
public:
    
    int powOf2(int y,vector<int> &dp){
        int mod = 1e9 +7;
        if(dp[y]!=0) return dp[y];
        
        return dp[y] = 2*powOf2(y-1,dp) % mod;
        
    }
    
    int numSubseq(vector<int>& nums, int target) {
        int mod = 1e9 +7;
        sort(begin(nums),end(nums));
        vector<int> dp(1e5,0);
        dp[0]=1;
        int i=0,j=nums.size()-1;
        int ans=0;
        while(i<=j){
            if(nums[i]+nums[j]<=target){
                ans=ans%mod;
                ans+=powOf2(j-i,dp);
                i++;
            }else{
                j--;
            }
            
        }
        return ans%mod;
    }
};
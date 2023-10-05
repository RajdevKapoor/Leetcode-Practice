class Solution {
public:
    int jump(vector<int>& nums) {
                
        int n=nums.size();
        vector<int> dp(n,1e9);
        
        dp[n-1]=0;
        
        for(int i=n-2;i>=0;i--){
            
            int jumps=nums[i];
            
            for(int j=0;j<=jumps;j++){ 
                if(i+j<n){
                    dp[i]=min(dp[i],dp[i+j]);
                }
                
            }
            
           
         dp[i]++;
            
            
            
        }
        
        return dp[0];
    }
};
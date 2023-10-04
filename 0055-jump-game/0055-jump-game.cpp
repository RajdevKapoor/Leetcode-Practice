class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> dp(n,false);
        
        dp[n-1]=true;
        
        for(int i=n-2;i>=0;i--){
            
            int jumps=nums[i];
        
            for(int j=0;j<=jumps;j++){
                
                if(i+j<n and dp[i+j]==true){
                    dp[i]=true;
                    break;
                }
                
            }
            
            
        }
        
        return dp[0];
        
    }
};
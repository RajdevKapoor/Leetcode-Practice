class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<bool> dp(n,false);
        
        dp[n-1]=true;
        
        int i=n-2;
        
        while(i>=0){
            
            
            for(int j=0;j<=nums[i] && i+j<n;j++){
                int iCanGoTo = j+nums[i];                
                 if(dp[i+j]==true) 
                {
                    dp[i]=true; 
                    break;
                }               
            }
            i--;
        }
        
        return dp[0];
        
    }
};
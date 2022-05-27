class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n=nums.size();
        vector <int> dp (n,INT_MAX);
        
        dp[n-1]=0;
        
        for(int i=n-2;i>=0;i--){
            int jumps = nums[i];
            
            int min = dp[i];
            
            for(int j=1;j<=jumps and i+j<n;j++){
                if(INT_MAX != dp[i+j] and dp[i+j]<min){
                    min=dp[i+j];
                }
            }
            
            if(min!=INT_MAX){
                dp[i]=min+1;
            }
            
        }
        
        return dp[0];
        
    }
};
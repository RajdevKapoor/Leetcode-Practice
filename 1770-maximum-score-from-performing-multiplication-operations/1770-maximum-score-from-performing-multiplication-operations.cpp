class Solution {
public:
    
    int maximumScore(vector<int>& nums, vector<int>& mul) {
        
        int n = nums.size();
        int m = mul.size();
        
        int dp[m+1];
        
        dp[0] = mul[0] * nums[n-1];
        dp[1] = mul[0] * nums[0];
            
        for (int i=1 ; i<m ; i++) {
		
            dp[i+1] = dp[i] + mul[i] * nums[i];  
			
            for (int j=i ; j>0 ; j--) {
                dp[j] = max( dp[j] + mul[i] * nums[n-i+j-1], dp[j-1] + mul[i] * nums[j-1] );
            }
			
            dp[0] += mul[i] * nums[n-i-1];   
            
        }
        
        int ans = 1<<31;
        for (int i=0 ; i<=m ; i++)
            ans = max( ans, dp[i] );

        return ans;
        
    }
    
};
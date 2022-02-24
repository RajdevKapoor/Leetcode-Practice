class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n=nums.size();
        
        vector <int> dp(n,1);
        
        for(int i=1;i<n;i++){
            
            int j=i;
            
            while(j>=0){
                
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
                j--;
                
            }
                        
        }
        
        return *max_element(dp.begin(), dp.end());
        
    }
};
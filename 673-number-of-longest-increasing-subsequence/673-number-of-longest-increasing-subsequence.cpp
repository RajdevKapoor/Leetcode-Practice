class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1),count(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i] && dp[j]+1>=dp[i]){
                    if(dp[j]+1>dp[i]){
                        dp[i]=dp[j]+1;
                        count[i]=count[j];
                    }
                    else 
                        count[i]+=count[j];
                }
            }
        }
        int maxi=0,total_lis=0;
        for(int i=0;i<n;i++){
            if(dp[i]>maxi){
                maxi=dp[i];
                total_lis=count[i];
            }
            else if(dp[i]==maxi){
                total_lis+=count[i];
            }
        }
        return total_lis;
        
    }
};
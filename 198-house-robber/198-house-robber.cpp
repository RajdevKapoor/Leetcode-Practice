class Solution {
public:
    int rob(vector<int>& nums) {
        int n =nums.size();
        
        if(n==1){
            return max(nums[0],0);
        }
        if(n==2){
            return max(0,max(nums[0],nums[1]));
        }
        
        vector<int> dp (n+1,0);
        
        dp[0]=max(nums[0],0);
        dp[1]=max(0,max(nums[0],nums[1]));
        
        for(int i=2;i<nums.size();i++){
            int op1 = nums[i]+dp[i-2]; 
            int op2 = dp[i-1];
            
            dp[i]=max(op1,op2);
        }
        
        return dp[n-1];
        
    }
};
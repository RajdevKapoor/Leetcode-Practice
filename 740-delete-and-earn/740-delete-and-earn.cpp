class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        int n=nums.size();
        
        if(n==0){
            return 0;
        }
        if(n==1){
            return nums[0];
        }
        
        vector <int> count(10001,0);
        vector <int> dp(10001,0);
        
        for(int x:nums){
            count[x]++;
        }
        
        
        dp[0]=count[0] * 0;
        dp[1]=max(count[0] * 0 ,count[1] * 1);
        
        for(int i=2;i<count.size();i++){
            
            int op1 = (count[i] * i) + dp[i-2];
            int op2 = dp[i-1];
            
            dp[i]=max(op1,op2);
        }
        
        return dp[count.size()-1];
        
        
    }
};
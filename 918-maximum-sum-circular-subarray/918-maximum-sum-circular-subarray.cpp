class Solution {
public:
    int kadanes(vector<int>& nums){
        int sum = 0;
        int ans=INT_MIN;
        for(int x:nums){
            sum+=x;
            ans=max(sum,ans);
            if(sum<0){
                sum=0;
            }
        }
        
        return ans; 
    }
    
    int maxSubarraySumCircular(vector<int>& nums) {
        
        if(nums.size()==0) return 0;
        
        int op1 = kadanes(nums);
        int sum = 0;
        
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            nums[i]*=-1;
        }
        
        int t = kadanes(nums);
        
        if(sum+t==0) return op1;
        
        return max(op1,sum+t);
          
        
    }
};
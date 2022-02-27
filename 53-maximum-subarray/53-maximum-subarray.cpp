class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int ans=INT_MIN;
        
        //Kadanes
        
        for(int x:nums){
            sum+=x;
            ans=max(sum,ans);
            if(sum<0){
                sum=0;
            }
            
            
        }
        
        return ans;
    
    }
};
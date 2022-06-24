class Solution {
public:
    
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n=nums.size();
        
        int i=0,j=0;
        int sum=0;
        
        int ans = INT_MAX;
        
        while(j<n){
            
            while(j<n and sum<target){
                sum+=nums[j++];
            }
            
            while(i<j and sum>=target){
                ans = min(ans,j-i+1);
                sum-=nums[i++];
            }
            
        }
        
        if(ans==INT_MAX){
            return 0;
        }
        return ans-1;
    }
};
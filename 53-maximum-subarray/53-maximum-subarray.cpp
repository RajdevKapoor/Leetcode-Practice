class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=INT_MIN;
        int ans=0;
        
        for(auto x: nums){
            ans+=x;
            sum=max(sum,ans);
            if(ans<0) {
                ans=0;
            }
            
        }
        
        return sum;
    }
};
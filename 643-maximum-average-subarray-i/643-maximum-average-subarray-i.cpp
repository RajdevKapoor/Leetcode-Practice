class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        int i=0;
        
        double sum = 0;
        
        for(;i<k;i++){
            sum+=nums[i];
        }
        
        double ans=sum;
        int j=0;
        for(;i<nums.size();i++){
            sum+=nums[i]-nums[j++];
            ans=max(ans,sum);
        }
        return ans/k;
    }
};
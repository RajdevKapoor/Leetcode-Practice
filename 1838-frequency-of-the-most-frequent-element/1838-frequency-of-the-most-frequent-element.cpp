class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());
        
        long long int sum=nums[0];
        int ans=1;
        int i=0,j=1;
        
        while(j<nums.size()){
            
            sum+=nums[j];
            
            while(i<j and (long long)nums[j]*(j-i+1)-sum>k){
                sum-=nums[i];
                i++;
            }

            ans=max(ans,j-i+1);
            
            j++;
        }
        
        return ans;
    }
};
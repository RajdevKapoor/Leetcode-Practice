class Solution {
public:
    int sum(vector<int>& nums){
        int sum=0;
        for(auto x:nums){
            sum+=x;
        }
        
        return sum;
    }
    
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++){
            
            if(nums[i]<0){
                nums[i]*=-1;
                k--;
            }
            if(k==0){
                return sum(nums);
            }
            
        }
        
        if(k%2==0){
            return sum(nums);
        }
        
        int l=*min_element(nums.begin(),nums.end());
        return sum(nums)-(2*l);
        
        
        
    }
};
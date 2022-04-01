class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        if(k<=1){
            return 0;
        }
        
        int l=0,r=0,pd=1,count=0;
        
        while(r<nums.size()){
            pd*=nums[r];
            
            while(pd>=k){
                pd/=nums[l];
                l++;
            }
            count+= 1 + r -l;
            r++;
        }
        
        return count;
        
    }
};
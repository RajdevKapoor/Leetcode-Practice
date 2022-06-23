class Solution {
public:
    int findMin(vector<int>& nums) {
        
        if(nums.size()==1) return nums[0];
        
        if(nums[0] < nums[nums.size()-1])
            return nums[0];
        
        int l=0,r=nums.size()-1;
        int mid ;
        
        while(l<=r){
            mid = (l+r)/2;
            
            if(nums[mid]>nums[mid+1]){
                return nums[++mid];
            }
            
            else if(nums[mid]<nums[mid-1]){
                return nums[mid];
            }
            
            else if(nums[mid]>=nums[l]){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        
        return min(nums[mid],nums[0]);
        
    }
};
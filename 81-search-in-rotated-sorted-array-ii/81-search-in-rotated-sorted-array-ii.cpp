class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        if(nums.size()==0){
            return false;
        }
        
        int l = 0;
        int r = nums.size()-1;
        
        while(l<=r){
            
            while(l<r and nums[l]==nums[l+1]) l++;
            while(l<r and nums[r]==nums[r-1]) r--;
            
            int mid = l + (r-l)/2;
            
            if(nums[mid]==target) return true;
            
            if(nums[mid]>=nums[l]){
                
                if(target>=nums[l] and target<=nums[mid]){
                    r=mid-1;
                }else{
                    l=mid+1;
                }
            }else{
                if(target>nums[mid] and target <=nums[r]){
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }
        
        }
        
        
        return false;
    }
};
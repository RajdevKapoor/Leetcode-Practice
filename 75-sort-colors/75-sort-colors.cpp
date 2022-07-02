class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int low=0;
        int high=nums.size()-1;
        int mid=low;
        
        
        while(mid<=high){
            int n=nums[mid];
            
            if(n==0){
                swap(nums[low++],nums[mid++]);
            }else if(n==1){
                mid++;
            }else{
                swap(nums[mid],nums[high--]);
            }
        }
        
    }
};
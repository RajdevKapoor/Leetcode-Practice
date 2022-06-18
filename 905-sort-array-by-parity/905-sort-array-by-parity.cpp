class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        int n=nums.size()-1;
        
        int i=0,j=n;
        
        while(i<j){
            if(nums[i]%2==1 and nums[j]%2==0){
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
            else if(nums[i]%2==0 and nums[j]%2==1){
                i++;
                j--;
            }
            else if(nums[i]%2==0 and nums[j]%2==0){
                i++;
            }else{
                j--;
            }
        }
        
        return  nums;
    }
};
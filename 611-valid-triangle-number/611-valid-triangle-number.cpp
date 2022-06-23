class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size()<2){
            return 0;
        }
        sort(nums.begin(),nums.end());
        
        int ans=0;
        for(int i=nums.size()-1;i>1;i--){
            
            int l=0;
            int r=i-1;
            
            while(l<r){
                if(nums[l]+nums[r]>nums[i]){
                    ans+=r-l;
                    r--;
                }else{
                    l++;
                }
            }
            
        }
        
        return ans;
        
    }
};
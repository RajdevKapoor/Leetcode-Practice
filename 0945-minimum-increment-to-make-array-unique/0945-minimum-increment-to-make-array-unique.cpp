class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int ans=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<= nums[i-1]){
                int nv = nums[i-1]+1;
                ans+= nv-nums[i];
                nums[i]=nv;
            }
            
        }
        return ans;
    }
};
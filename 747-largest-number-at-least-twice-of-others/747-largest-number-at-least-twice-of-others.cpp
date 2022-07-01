class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        
        int max=nums[0];
        int id=0;
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            
            if(nums[i]>max){
                max=nums[i];
                id=i;
            }
        }
        
        for(int n:nums){
            if(n==max)continue;
            if(max<2*n){
                return -1;
            }
        }
        return id;
    }
};
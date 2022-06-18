class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n=nums.size();
        vector<int> lmin (n+1,INT_MAX);
        
        for(int i=n-1;i>0;i--){
            lmin[i]=min(nums[i],lmin[i+1]);
        }
        int msf = nums[0];
        for(int i=0;i<n;i++){
            
            if(nums[i]>msf){
                msf = nums[i];
            }
            
            if(msf<=lmin[i+1]){
                return 1+i;
            }
            
        }
        return 0;
    }
};
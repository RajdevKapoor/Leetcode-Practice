class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> dpl(n,1),dpr(n,1);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    dpl[i]=max(dpl[i],dpl[j]+1);
                }
            }
        }
        
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(nums[j]<nums[i]){
                     dpr[i]=max(dpr[i],dpr[j]+1);
                }
            }
        }
        
        
        int mx=0;
        
        for(int i=0;i<n;i++){
            if(dpl[i]>1 and dpr[i]>1)mx=max(mx,dpl[i]+dpr[i]-1);
            
        }
        
        return n-mx;
        
    }
};
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n=nums.size();
        long long int ans = INT_MIN;
        
        long long int pd=1;
        
        for(int i=0;i<n;i++){
            pd*=nums[i];
            ans=max(ans,pd);
            
            if(pd==0){
                pd=1;
            }
        }
        pd=1;
        
        for(int i=n-1;i>=0;i--){
            pd*=nums[i];
            ans=max(ans,pd);
            
            if(pd==0){
                pd=1;
            }
            
        }
        
        return ans;        
        
    }
};
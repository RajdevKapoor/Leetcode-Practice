class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> ans(n,1);
        int pd =1 ;
        vector<int> right (n,1);
        
        for(int i=n-1;i>=0;i--){
            pd*=nums[i];
            right[i]=pd;
        }
        pd=1;
        for(int i=0;i<n;i++){
            ans[i] = pd * (i==n-1?1:right[i+1]);
            pd*=nums[i];
        }
        return ans;
        
    }
};
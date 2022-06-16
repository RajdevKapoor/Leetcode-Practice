class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans (n,0);
        
        int i=0;
        int j=n-1;
        
        for(int k=n-1;k>=0;k--){
            ans[k]=max(abs(nums[i]),abs(nums[j]));
            cout<<ans[k]<<" ";
            if(ans[k]==abs(nums[i])){
                i++;
            }else{
                j--;
            }
            ans[k]*=ans[k];
            
        }
        return ans;
    }
};
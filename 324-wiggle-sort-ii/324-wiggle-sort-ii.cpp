class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        
        // we will take the use of an extra array to avoid numbers if they are equal 
        int n=nums.size();
        vector<int>ans(n);
        
        // sort the array first
        sort(nums.begin(),nums.end());
        
        // we'll use 2-pointer approach
        int i=1;
        int j=n-1;
        
        while(i<n){
            ans[i]=nums[j];
            i+=2;
            j--;  // first we will all the greater numbers
        }
        
        i=0;
        
        while(i<n){
            ans[i]=nums[j];
            i+=2;
            j--;  // now  we will all the smaller numbers
        }
        
        // since we've to return the original array copy the values to the original array
        
        for(int k=0;k<n;k++)
            nums[k]=ans[k];
        
    }
};
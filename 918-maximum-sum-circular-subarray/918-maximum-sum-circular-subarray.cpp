class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        bool positive=false; int sum=0,maxi=nums[0];
        int cmax1=0,gmax1=nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0) positive=true;
            sum+=nums[i];
            maxi=max(maxi,nums[i]); 
            cmax1+=nums[i]; //kadane's algorithm
            if(nums[i]>cmax1) cmax1=nums[i];
            gmax1=max(gmax1,cmax1);
            nums[i]*=-1; //inverting all array elements 
        }

        if(!positive) return maxi; //if all elements of the array are -ve, we just return max element.
      int cmax2=0,gmax2=nums[0];
        for(auto x: nums){
            cmax2+=x; //kadane's algo on inverted array
            if(x>cmax2) cmax2=x;
            gmax2=max(gmax2,cmax2);
        }
 //gmax1=kadane's solution of one-interval and gmax2=kadane's solution of two-interval subarray       
        int remove=-1*(gmax2); //min sum subarray to be removed
        return max(sum-remove,gmax1);
  
    }
};
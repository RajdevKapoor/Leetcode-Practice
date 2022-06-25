class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        int duplicate =-1, missing =-1;
        
        for (int n: nums) {
            if (nums[abs(n) - 1] < 0)
                duplicate = abs(n);
            else
                nums[abs(n) - 1] *= -1;
        }
        
        for(int i=1;i<nums.size();i++){
            if(nums[i]>0){
                missing=i+1;
                return {duplicate,abs(missing)};
            }
        }
        return {duplicate,abs(missing)};
    }
};
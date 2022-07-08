class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 1;
        int l = 1;
        for(int i = 0;i<nums.size()-1;i++)
        {
            if(nums[i] < nums[i+1])
                l++;
            else
                l = 1;
             ans = max(l,ans);
        }
        return ans;
    }
};
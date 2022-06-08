class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        if (nums.size() == 1){return 0;}
        sort(nums.begin(), nums.end());
        int n=nums.size()-1;
        int ans =nums[n]-nums[0];
        
        for (int divide = 0; divide < nums.size() - 1; divide++){
            int mx = max(nums[divide] + k, nums[n] - k);
            int mn = min(nums[0] + k, nums[divide + 1] - k);
            ans = min(ans, mx - mn);
        }
        return ans;
    }
};
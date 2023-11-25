class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int>ans; // prefix sum array
        int n = nums.size();

        ans.push_back(nums[0]);
        for(int i = 1; i < n; i++){
            ans.push_back(nums[i] + ans.back());
        }
        vector<int>res;

        for(int i = 0; i < n; i++){
            int prefix_sum = ans[i] - nums[i];
            int suffix_sum = ans[n-1] - ans[i];
            res.push_back((nums[i]*i - prefix_sum) + (suffix_sum - nums[i]*(n-i-1)));
        }
        
        return res;
    }
};
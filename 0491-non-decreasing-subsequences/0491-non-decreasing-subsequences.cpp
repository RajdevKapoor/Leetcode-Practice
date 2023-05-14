class Solution {
public:
    void f(int i, vector<int> nums, int prev, vector<int> & carry, set<vector<int>> &res) {
        if(i == nums.size()) {
            if(carry.size() >= 2) {
                res.insert(carry);
            }
            return;
        }
        f(i + 1, nums, prev, carry, res);
        if(prev == -1 || nums[prev] <= nums[i]) {
            carry.push_back(nums[i]);
            f(i + 1, nums, i, carry, res);
            carry.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> carry;
        f(0, nums, -1, carry, res);
        vector<vector<int>> ans;
        for(vector<int> x : res) ans.push_back(x);
        return ans;
    }
};
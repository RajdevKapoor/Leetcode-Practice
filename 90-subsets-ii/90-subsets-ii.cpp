class Solution {
public:
    void subSet2(vector<int>& nums, int idx,vector<vector<int>> &res, vector<int> &curr){
        res.push_back(curr);
        for(int i=idx;i<nums.size();++i){
            if(i>idx && nums[i]==nums[i-1]) continue;
            curr.push_back(nums[i]);
            subSet2(nums,i+1,res,curr);
            curr.pop_back();
        }
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> curr;
        subSet2(nums,0,res,curr);
        return res;
    }
};
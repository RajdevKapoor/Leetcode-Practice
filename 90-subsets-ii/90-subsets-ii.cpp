class Solution {
public:
    void subSet2(vector<int>& nums, int idx,vector<vector<int>> &res, vector<int> &curr){
        
        if(idx==nums.size()){
            res.push_back(curr);
            return;
        }
        curr.push_back(nums[idx]);
        subSet2(nums,idx+1,res,curr);
        curr.pop_back();
        
        while(idx+1<nums.size() and nums[idx]==nums[idx+1]){
            idx++;
        }
        subSet2(nums,idx+1,res,curr);
        
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
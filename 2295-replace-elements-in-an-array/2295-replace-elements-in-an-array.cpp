class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& op) {
        
        unordered_map <int,int> m;
        
        for(int i=0;i<nums.size();i++){
            m[nums[i]]=i;
        }
        
        for(auto o:op){
            int idx =m[o[0]];
            nums[idx]=o[1];
            m[o[1]]=idx;
        }
        
        return nums;
        
    }
};
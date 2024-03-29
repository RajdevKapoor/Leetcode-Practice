class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
       unordered_map<int,vector<int>>m;
       vector<int>ans;
       int mx = 0;
       for(int i = nums.size()-1; i>-1; --i){
           for(int j = 0; j<nums[i].size(); ++j){
               m[i+j].push_back({nums[i][j]});
               mx = max(mx, i+j);
           }
       }
       for(int i = 0; i<=mx; ++i){
           for(auto x : m[i]) ans.push_back(x);
       }
        return ans;
    }
};
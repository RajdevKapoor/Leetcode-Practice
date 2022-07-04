class Solution {
public:
    void solve(vector<int>& candidates, int target,int i,vector<int> v,vector<vector<int>> &ans){
        
        if(i==candidates.size() or target==0){
            if(target==0) ans.push_back(v);
            return;
        }
        
        //pick
        if(candidates[i]<=target){
            v.push_back(candidates[i]);
            solve(candidates,target-candidates[i],i,v,ans);
            v.pop_back();
        }
        
        //notpick
        solve(candidates,target,i+1,v,ans);
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>v;
        solve(candidates,target,0,v,ans);
        return ans;
        
    }
};
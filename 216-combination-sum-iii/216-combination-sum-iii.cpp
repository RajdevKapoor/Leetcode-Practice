class Solution {
public:
    void solve(int i,vector<vector<int>> &ans,vector<int> &v,int k,int target){
        
        
        
        if(target==0 and v.size()==k){
            ans.push_back(v);
            return;
        }
        
        if(i>9 || target<0){
            return;
        }
        
        //not take
        solve(i+1,ans,v,k,target);
        
        
        //take
        v.push_back(i);
        solve(i+1,ans,v,k,target-i);
        v.pop_back();
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans; 
        vector<int> v;
        
        solve(1,ans,v,k,n);
        
        return ans;
        
        
        
    }
};
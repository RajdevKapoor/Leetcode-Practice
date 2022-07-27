class Solution {
public:
    void solve( vector<vector<int>> &ans, vector<int> &v, int i, int n, int k){
        
        if(i>n+1) return;
        
        if(v.size()==k){
            ans.push_back(v);
            return;
        }
        
        //not take
        solve(ans,v,i+1,n,k);
        
        //take
        if(i<=n){
            v.push_back(i);
            solve(ans,v,i+1,n,k);
            v.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>> ans;
        vector<int> v;
        solve(ans,v,1,n,k);
        return ans;
        
    }
};
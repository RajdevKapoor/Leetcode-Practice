class Solution {
public:
    map<int, vector<int>>adj;
    int ans = 0, maxi = 0;
    
    void dfs(int manager, vector<int>&informTime){
        maxi = max(maxi, ans);
        for(auto employee : adj[manager]){
            ans += informTime[manager];
            
            dfs(employee, informTime);
            
            ans-= informTime[manager];
        }
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        for(int i=0;i<manager.size();i++){
            if(manager[i]!=-1)
                adj[manager[i]].push_back(i);
        }
        dfs(headID, informTime);
        return maxi;
    }
};
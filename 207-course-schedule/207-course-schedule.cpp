class Solution {
public:
    bool iscycle(vector<int>adj[],vector<int> &vis,int id){
        if(vis[id]==1)
            return true;
        if(vis[id]==0){
            vis[id]=1;
            for(auto edge : adj[id]){
                if(iscycle(adj,vis,edge))
                    return true;
            }
        }
        vis[id] = 2;
        return false;
    }
    
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int>adj[n];
        
        for(auto p : pre) {
            adj[p[0]].push_back(p[1]);
        }
        
        vector<int>visited(n , 0);
        
        for(int i = 0 ; i < n ; i++) {
            if(iscycle(adj,visited,i)) 
                return false;
        }
        return true;
    }
};
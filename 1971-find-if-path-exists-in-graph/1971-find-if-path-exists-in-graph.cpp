class Solution {
public:
    
    void DFS(unordered_map<int,vector<int>>&AdjList,int source, int destination, vector<bool>&visited,bool &ans){
        
        
        if(source == destination){
            ans = true;
            return;
        }
        visited[source] = true;
        for(auto u:AdjList[source]){
            if(visited[u] == false){
                DFS(AdjList,u,destination,visited,ans);
            }
        }
        
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination){
            return true;
        }
        vector<bool>visited(n,false);
        unordered_map<int,vector<int>>AdjList;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v = edges[i][1];
            AdjList[u].push_back(v);
            AdjList[v].push_back(u);
        }
        bool ans = false;
        DFS(AdjList,source,destination,visited,ans);
        return ans;
    }
};
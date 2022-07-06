class Solution {
public:
    void dfs(unordered_map<int,vector<int>>&graph,vector<bool> &visited,int node){
        
        visited[node]=true;
        
        for(auto neighbour: graph[node]){
            if(visited[neighbour]==false){
                dfs(graph,visited, neighbour);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        vector<bool> visited(n,false);
        
        int edges = connections.size();
        if(edges < n-1) return -1;
        
        unordered_map<int,vector<int>>graph;
        
        for(auto c:connections){
            int x=c[0];
            int y=c[1];
            
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        int count=0;
        for(int i=0;i<n;i++){
            
            if(visited[i]==false){
                dfs(graph,visited,i);
                count++;
            }
            
        }
        return count-1;
    }
};
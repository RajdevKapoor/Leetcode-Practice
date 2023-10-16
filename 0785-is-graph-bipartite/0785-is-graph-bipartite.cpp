class Solution {
public:
    bool bfs(int src,vector<vector<int>>& graph,vector<int> &color){
        color[src]=0;
        queue<int> q;
        q.push(src);
        
        while(!q.empty()){
            int u=q.front();
            q.pop();
            
            for(auto nbr:graph[u]){
                if( color[nbr]==-1){
                    color[nbr]=1-color[u];
                    q.push(nbr);
                }
                else if(color[nbr]==color[u])return false; 
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int> color(v,-1);
        for(int i=0;i<v;i++){
            if(color[i]==-1){
                if(!bfs(i,graph,color))return false;
            }
        }
        return true;
        
        
    }
};
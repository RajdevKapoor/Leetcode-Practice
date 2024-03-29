class Solution {
public:
    bool bfs(int src,vector<vector<int>>& graph,vector<int> &color){
        color[src]=0;
        queue<int> q;
        q.push(src);
        
        while(!q.empty()){
            int u=q.front();
            q.pop();
            
            
            for(auto i:graph[u]){
                if( color[i]==-1){
                    color[i]=1-color[u];
                    q.push(i);
                }
                else if(color[i]==color[u])return false; 
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
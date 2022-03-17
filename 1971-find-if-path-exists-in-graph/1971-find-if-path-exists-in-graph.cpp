class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        unordered_map<int,vector<int>> g;
        
        for(auto e : edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        
        vector<bool> visited(n,0);        
        queue<int> q;
        q.push(source);
        visited[source] = 1;
        
        while(q.size()>0){
            int curr = q.front();
            q.pop();
            
            if(curr == destination){
                return 1;
            }
            
            for(auto v: g[curr]){
                if(visited[v]==false){
                    visited[v]=true;
                    q.push(v);
                }
            }
        }
        
        return 0;
        
    }
};
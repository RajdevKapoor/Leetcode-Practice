class Solution {
public:
    bool bfs(unordered_map<int,vector<int>>& adj,vector<int>& color,int src)
    {
        queue<int> q;
        q.push(src);
        color[src]=0;
        
        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            
            for(auto i: adj[front])
            {
                if(color[i]==-1)
                {
                    q.push(i);
                    color[i] = 1-color[front];
                }
                
                if(color[i]==color[front]) return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<dislikes.size();i++)
        {
            int u = dislikes[i][0];
            int v = dislikes[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> color(n+1,-1);
        for(int i=1;i<=n;i++)
        {
            if(color[i]==-1)
            {
                if(!bfs(adj,color,i)) return false;
            }
        }
        return true;
    }
};
class Solution {
public:
     int minReorder(int n, vector<vector<int>>& connections) {
        
    vector<vector<pair<int,int>>>adj(n);
        for(int i =0  ; i <connections.size();i++){
            adj[connections[i][0]].push_back({connections[i][1],1});
             adj[connections[i][1]].push_back({connections[i][0],0});
        }
    queue<int>q;
        vector<int>visited(n,0);
        visited[0] = 1;
        q.push(0);
        int dis = 0;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            for(auto j : adj[it]){
                if(!visited[j.first]){
                    visited[j.first]=1;
                    dis+=j.second;
                    q.push(j.first);
                }
            }
        }
        return dis;
    }
};
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& g) {
        int n = g.size();
        int all = (1<<n)-1;
        queue<array<int,3>>q;
        set<pair<int,int>>vis;
        for(int i=0;i<n;i++){
            int mask = (1<<i);
            q.push({i,0,mask});
            vis.insert({i,mask});
        }
        
        while(!q.empty()){
            auto curr = q.front();q.pop();
            int node = curr[0];
            int dist = curr[1];
            int mask = curr[2];
            
            for(int kid:g[node]){
                int newMask = (mask | (1<<kid));
                if(newMask==all) return dist+1;
                if(vis.find({kid,newMask})!=vis.end()) continue;
                q.push({kid,dist+1,newMask});
                vis.insert({kid,newMask});
            }
        }
        return 0;
    }
};
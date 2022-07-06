class Solution {
public:
    #define ll long long
    const int mod = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        
        unordered_map<int,vector<pair<int,int>>> graph;
        
        for(auto road:roads){
            int x=road[0];
            int y=road[1];
            int time = road[2];
            
            graph[x].push_back({y,time});
            graph[y].push_back({x,time});
        }
        
        unordered_map<ll,ll> distTo;
        
        for(int i=0;i<n;i++) distTo[i]=LONG_MAX;
        
        distTo[0]=0;
        priority_queue<pair<ll,ll> ,vector<pair<ll,ll>  >,greater<pair<ll,ll> >> q;
        q.push({0,0});
        vector<ll> way(n, 0);
        way[0]=1;
        ll ans=1;
        
        while(q.size()){
            ll distToParent = q.top().first;
            ll parent = q.top().second;
            q.pop();
            
            for(auto nbr:graph[parent]){
                ll child = nbr.first;
                ll distParentToChild=nbr.second;
                
                if(distParentToChild+distToParent<distTo[child]){
                    distTo[child]=distParentToChild+distToParent;
                    q.push({distTo[child],child});
                    
                    way[child] = way[parent];
                    
                }
                else if(distParentToChild+distToParent==distTo[child]){
                   way[child] = (way[parent] + way[child]) % mod;
                }
            }
            
        }
        
        return way[n - 1] % mod;
    }
};
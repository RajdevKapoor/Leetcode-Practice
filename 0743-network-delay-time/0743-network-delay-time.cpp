class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        unordered_map<int,vector<pair<int,int>>> graph;
        
        for(auto t:times){
            graph[t[0]].push_back({t[1],t[2]});
        }
        
        unordered_map<int,int> distTo;
        
        for(int i=1;i<=n;i++){
            distTo[i]=INT_MAX;
        }
        
        distTo[k]=0;
        
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>>> pq;
        
        pq.push({0,k});
        
        while(pq.size()){
            int parent = pq.top().second;
            pq.pop();
            
            for(auto nbr:graph[parent]){
                int childNode = nbr.first;
                int distanceParentToChild = nbr.second;
                
                if( distTo[parent] + distanceParentToChild < distTo[childNode]){
                    distTo[childNode]=distTo[parent] + distanceParentToChild;
                    pq.push({distTo[childNode],childNode});
                }
                
            }
            
        }
        
        int ans=-1;
        
        for(auto d:distTo){
            ans=max(ans,d.second);
            if(ans==INT_MAX) return -1;
        }
        
        return ans;
        
    }
};
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        unordered_map<int,vector<pair<int,double>>> graph;
        
        for(int i=0;i<succProb.size();i++){
            
            int x = edges[i][0];
            int y = edges[i][1];
            double wt = succProb[i];
            
            graph[x].push_back({y,wt});
            graph[y].push_back({x,wt});
            
        }
        
        
        unordered_map<int,double> distTo;
        
        for(int i=0;i<n;i++){
            distTo[i]=0.0;
        }
        
        distTo[start]=1.0;
        
        //priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>>pq;
        priority_queue<pair<double, int>> pq;
        
        pq.push({distTo[start],start});
        
        while(pq.size()){
            double distUptoParent = pq.top().first;
            int parent = pq.top().second;
            pq.pop();
            
            for(auto nbr:graph[parent]){
                
                int child = nbr.first;
                double distParentToChild = nbr.second;
                
                if(distParentToChild*distUptoParent>distTo[child]){
                    distTo[child]=distParentToChild*distUptoParent;
                    pq.push({distTo[child],child});
                }
                
            }
            
        }
        
        
        return distTo[end]==0.0?0:distTo[end];
    }
};
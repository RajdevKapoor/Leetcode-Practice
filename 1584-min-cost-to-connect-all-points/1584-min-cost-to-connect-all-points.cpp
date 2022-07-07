class Solution {
public:
    static int findParent(int u, vector<int> &parent, vector<int> &rank){
        if(parent[u]==u){
            return u;
        }
        return parent[u]=findParent(parent[u], parent, rank);
    }
    static void unionByRank(int u, int v, vector<int> &parent, vector<int> &rank){
        if(rank[u]<rank[v]){
            parent[u] = v;
        }
        else if(rank[u]>rank[v]){
            parent[v] = u;
        }
        else{
            parent[v] = u;
            rank[u]++;
        }
    }
    static bool comp(const vector<int> &v1, const vector<int> &v2){
        return v1[2]<v2[2];
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<int> parent(1001, 0);
        vector<int> rank(1001, 0);
        vector<vector<int>> edges;
        for(int i=0; i<points.size(); i++){
            int x1 = points[i][0];
            int y1 = points[i][1];
            for(int j=i+1; j<points.size(); j++){
                int x2 = points[j][0];
                int y2 = points[j][1];
                
                int dist = abs(x2-x1)+abs(y2-y1);
                
                edges.push_back({i, j, dist});
            }
        }
        
        for(int i=0; i<1001; i++){
            parent[i] = i;
            rank[i] = 0;
        }
        
        sort(edges.begin(), edges.end(), comp);
        
        int ans = 0;
        
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            int pu = findParent(u, parent, rank);
            int pv = findParent(v, parent, rank);
            
            if(pu!=pv){
                unionByRank(pu, pv, parent, rank);
                ans+=w;
            }
        }
        
        return ans;
    }
};
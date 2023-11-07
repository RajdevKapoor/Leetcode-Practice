class Solution {
private:
    double get_dist(const vector<int>& lhs, const vector<int>& rhs){
        return sqrt(pow(lhs[0] - rhs[0], 2) + pow(lhs[1] - rhs[1], 2));
    }
    
    int bfs(unordered_map<int, vector<int>>& graph, int i, int n){
        vector<bool> visited(n, false);
        visited[i] = true;
        
        queue<int> q;
        q.push(i);
        
        int count = 0;
        while(!q.empty()){
            int curr = q.front(); 
            q.pop();
            count++;
            for(int neigh: graph[curr]){
                if(!visited[neigh]){
                    q.push(neigh);
                    visited[neigh] = true;
                }  
            }
        }
        return count;
    }
public:
    int maximumDetonation(const vector<vector<int>>& bombs) {
        int n = bombs.size();
        unordered_map<int, vector<int>> graph;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                auto lhs = bombs[i];
                auto rhs = bombs[j];
                double dist = get_dist(lhs, rhs);
                
                if(dist <= lhs[2]){
                    graph[i].push_back(j);
                }
                if(dist <= rhs[2]){
                    graph[j].push_back(i);
                }
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            int detonate = bfs(graph, i, n);
            ans = max(detonate, ans);
        }
        return ans;
    }
};
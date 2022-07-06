class Solution {
public:
    bool checkCycle(int i, unordered_map <int,vector<int>> &graph,vector<bool>&visited, vector<bool>&currVisited){
        
        visited[i]=true;
        currVisited[i]=true;
        
        for(auto nbr:graph[i]){
            
            if(visited[nbr]==false){
                if(checkCycle(nbr,graph,visited,currVisited)){
                    return true;
                }
            }else{
                if(currVisited[nbr]){
                    return true;
                }
            }
        }
        
        
        currVisited[i]=false;
        return false;
    }
    
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        
        unordered_map <int,vector<int>> graph;
        vector<bool>visited(n, false), currVisited(n, false);
        for(auto x: prerequisites){
            int a = x[0];
            int b = x[1];
            graph[a].push_back(b);
        }
        
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                if(checkCycle(i,graph,visited,currVisited)){
                    return false;
                }
            }
        }
        return true;
    }
};
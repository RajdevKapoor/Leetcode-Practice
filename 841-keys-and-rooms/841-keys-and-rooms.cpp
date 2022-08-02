class Solution {
public:
    void dfs(vector<vector<int>>& rooms,vector<bool> &visited, int node){
        
        if(visited[node]) return;
        
        visited[node]=true;
        
        for(auto nbr:rooms[node]){
            dfs(rooms,visited,nbr);
        }
        
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        vector<bool> visited(rooms.size(),false);
        
        dfs(rooms,visited,0);
        
        
        for(int i=0;i<rooms.size();i++){
            if(visited[i]==false) return false;
        }
        return true;
    }
};
class Solution {
private:
    vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
public:
     void dfs(int i, int j, vector<vector<int>>& grid, queue<pair<int,int>> &q){

        if(i <0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != 1)
            return;
        
        grid[i][j] = -1;
        q.push({i,j});
        for(int k = 0; k<4; k++){
            
            int nx = i + dir[k][0];
            int ny = j + dir[k][1];
                    
            if(nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size() || grid[nx][ny] != 1){
                continue;
            }
            
            dfs(nx,ny,grid,q);
        }
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        
        int n=grid.size();
        
        queue<pair<int,int>>q;
        
        
        bool flag = false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                
                if(grid[i][j]){
                    dfs(i,j,grid,q);
                    flag=true;
                }
                
                if(flag) break;
            }
            if(flag) break;
        }
        
        int level =0;
        
        while(q.size()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                
                pair<int,int> p = q.front();
                q.pop();
                
                int x = p.first, y = p.second;
                
                for(int i = 0; i<4; i++){
                    int nx = x + dir[i][0];
                    int ny = y + dir[i][1];
                    
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n || grid[nx][ny] == -1){
                        continue;
                    }
                    if(grid[nx][ny] == 1) return level;
                    
                    grid[nx][ny] = -1;
                    q.push({nx,ny});
                }
            }
            
            level++;
        }
        
        return -1;
    }
};
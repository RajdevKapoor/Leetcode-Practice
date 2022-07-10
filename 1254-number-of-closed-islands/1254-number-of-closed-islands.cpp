class Solution {
public:
    void dfs(vector<vector<int>>& grid,int i,int j){
        if(i<0 or i>=grid.size() or j<0 or j>=grid[0].size() or grid[i][j]==1) return;
        
        grid[i][j]=1;
        dfs(grid,i+1,j); 
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
        
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 or i==n-1 or j==0 or j==m-1) and(grid[i][j]==0)){
                    dfs(grid,i,j);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    ans++;
                    dfs(grid,i,j);
                }
            }
        }
        return ans;
    }
};
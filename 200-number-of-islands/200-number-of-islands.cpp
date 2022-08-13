class Solution {
public:
    int n,m;
    
    void clear(vector<vector<char>>& grid,int i,int j){
        
        if(i<0 or i>=n or j<0 or j>=m or grid[i][j]=='0') return;
        
        grid[i][j]='0';
        clear(grid,i+1,j); clear(grid,i-1,j); clear(grid,i,j+1); clear(grid,i,j-1);
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        n=grid.size();
        m=grid[0].size();
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    clear(grid,i,j);
                }
            }
        }
        
        return ans;
        
    }
};
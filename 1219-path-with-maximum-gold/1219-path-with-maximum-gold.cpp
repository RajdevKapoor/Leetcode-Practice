class Solution {
public:
   
    
    int solve(int i,int j, int m,int n,vector<vector<int>>& grid){
        
        if(i<0 or i==m or j<0 or j==n or grid[i][j]==0) return 0;
        
        int temp = grid[i][j];
         grid[i][j]=0;
        
        int u = solve(i-1,j,m,n,grid);
        int d = solve(i+1,j,m,n,grid);
        int r = solve(i,j+1,m,n,grid);
        int l = solve(i,j-1,m,n,grid);
        grid[i][j]=temp;
        
        return temp + max(u,max(d,max(l,r)));
        
        
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
         int ans = 0;
        
        
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans=max(solve(i,j,m,n,grid),ans);
            }
        }
        
        return ans;
        
        
       
        
        
    }
};
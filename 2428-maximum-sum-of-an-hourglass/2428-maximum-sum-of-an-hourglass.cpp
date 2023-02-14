class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        if(n<3 or m<3) return 0;
        
        int ans=0;
        
        
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                
                int temp = grid[i-1][j-1]+grid[i-1][j]+grid[i-1][j+1] + grid[i][j] + grid[i+1][j-1]+grid[i+1][j]+grid[i+1][j+1];
                ans=max(ans,temp);
                
            }
            
        }
        
        return ans;
        
        
    }
};
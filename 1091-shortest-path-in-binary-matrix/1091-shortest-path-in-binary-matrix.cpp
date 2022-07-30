class Solution {
public:
    int dx[8] = {1,0,-1,0,1,-1,1,-1};
    int dy[8] = {0,1,0,-1,-1,1,1,-1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0] != 0 || grid[n-1][m-1] != 0)
            return -1;
        
        if(grid.size() == 1 and grid[0].size() == 1 and grid[0][0] == 0) // {{0}} for this test case 
            return 1;
        
        queue<pair<int,int>> q;
        q.push({0,0});
        
        grid[0][0] = 1; //handling TLE as soon as i reach a cell with value 0 i mark it as 1 so that i do not revisit it
        
        int lvl = 0;
        while(!q.empty()){
            int s = q.size();
            lvl++;
            while(s--){
                auto p =q.front();
                q.pop();
                for(int i=0;i<8;i++){
                    int x = p.first+dx[i];
                    int y= p.second+dy[i];
                    
                    if(x<0 || x>=n || y<0 || y>=m || grid[x][y] != 0)
                        continue;
                    
                    grid[x][y] = 1; //handling TLE as soon as i reach a cell with value 0 i mark it as 1 so that i do not revisit it
                    
                    if(x == n-1 and y == m-1)
                        return lvl+1;
                    
                    q.push({x,y});
                }
            }
        }
            
        return -1;
    }
};
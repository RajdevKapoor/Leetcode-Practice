class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        queue<pair<int,int>> q;
        int fresh=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        if(fresh==0){
            return 0;
        }
        vector<int> dx={-1,0,1,0};
        vector<int> dy={0,-1,0,1};
        int count=0,result=0;
        while(!q.empty()){
            int len=q.size();
            for(int i=0;i<len;i++){
                auto current=q.front();
                q.pop();
                int currX=current.first,currY=current.second;
                for(int i=0;i<4;i++){
                    int x=currX+dx[i],y=currY+dy[i];
                    if(x>=0 && x<m && y>=0 && y<n && grid[x][y]==1){
                        q.push({x,y});
                        grid[x][y]=2;
                        count++;
                    }
                }
            }
            result++;
        }
        return fresh==count?result-1:-1;
    }
};
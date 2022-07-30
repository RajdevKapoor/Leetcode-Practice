class Solution {
public:
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int r=mat.size();
    int c=mat[0].size();
    queue<pair<int,int>> q;
    vector<vector<int>> ans(r,vector<int>(c,-1));
    
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            if(mat[i][j]==0){
                ans[i][j]=0;
                q.push({i,j});
            }
    
    vector<vector<int>> path={{-1,0},{0,1},{1,0},{0,-1}};
    while(!q.empty()){
        int nx=q.front().first;
        int ny=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int x=path[i][0]+nx;
            int y=path[i][1]+ny;
            if(x>=0 && y>=0 && x<r && y<c && ans[x][y]==-1){
                q.push({x,y});
                ans[x][y]=ans[nx][ny]+1;
            }
        }
    }
    return ans;
}
};
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        
        int m =maze.size();
        int n =maze[0].size();
        
        
        queue<pair<int,int>> q;
        q.push({e[0],e[1]});
        
        
        
        maze[e[0]][e[1]]='+';
        
        vector<vector<int>> dir= {{-1,0},{1,0},{0,-1},{0,1}};
        
        int level = 1;
        
        while(q.size()){
            
            int sz=q.size();
            
            for(int i=0;i<sz;i++){
                
                auto f = q.front();
                q.pop();
                int x = f.first; int y = f.second ;
                 for(int k = 0; k<4; k++){
                    int nx = x+dir[k][0];
                    int ny = y+dir[k][1];
                    
                    if(nx<0 or ny<0 or nx>=m or ny>=n or maze[nx][ny]=='+'){
                         continue;
                    }
                    
                    if(nx==0 or nx==m-1 or ny==0 or ny==n-1){
                        return level;
                    }
                    
                    maze[nx][ny] = '+';
                    q.push({nx,ny});
                }
                
                
            }
            
            level++;
        }
        
        return -1;
    }
};
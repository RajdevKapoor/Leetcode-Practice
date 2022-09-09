class Solution {
public:
    int n,m;
    
    bool isValid(int x,int y){
        if(x<0 or x>=n or y<0 or y>=m){
            return false;
        }
        
        return true;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        
        n=board.size();
        m=board[0].size();
        
        vector<vector<int>> temp(n, vector<int>(m, 0));
        
        int x[]={-1,-1,-1,0,0,1,1,1};
        int y[]={-1,0,1,-1,1,-1,0,1};
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int count = 0;
                
                for(int k=0;k<8;k++){
                    if(isValid(i+x[k],j+y[k]) and board[i+x[k]][j+y[k]]){
                        count++;
                    }
                }
                
                if(board[i][j]){
                    if(count<2 or count>3){
                        temp[i][j] = 0;
                    }else{
                        temp[i][j] = 1;
                    }
                }else{
                    if(count==3){
                        temp[i][j] = 1;
                    }
                }

            }
        }
        board=temp;
    }
};
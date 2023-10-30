class Solution {
public:
    bool solve(vector<vector<char>>& board, string word,int i, int j,int pos, int n, int m){
        
        if(word.size()==pos) return true;
        
        if(i<0 or i>=n or j<0 or j>=m or word[pos]!=board[i][j]){
           return false; 
        }
            char c = board[i][j];
            board[i][j] = '.';
            bool res1 = solve(board,word,i+1,j,pos+1,n,m); 
            bool res2 = solve(board,word,i-1,j,pos+1,n,m);
            bool res3 = solve(board,word,i,j+1,pos+1,n,m);
            bool res4 = solve(board,word,i,j-1,pos+1,n,m);
            board[i][j] = c;
            
    
        
        
        return res1 or res2 or res3 or res4;
        
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        int n = board.size();
        int m = board[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(solve(board,word,i,j,0,n,m)) return true;;
                }
            }
        }
        return false;
    }
};
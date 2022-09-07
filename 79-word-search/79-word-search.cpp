class Solution {
public:
    bool solve(vector<vector<char>>& board, string word,int i, int j,int pos, int n, int m){
        
        if(word.size()==pos) return true;
        
        if(i>=0 and i<n and j>=0 and j<m and word[pos]==board[i][j]){
            char c = board[i][j];
            board[i][j] = '.';
            bool res =  solve(board,word,i+1,j,pos+1,n,m) or solve(board,word,i-1,j,pos+1,n,m) or solve(board,word,i,j+1,pos+1,n,m) or solve(board,word,i,j-1,pos+1,n,m);
            board[i][j] = c;
            
            if(res) return true;
        }
        
        return false;
        
        
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
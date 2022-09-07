struct TrieNode{
        array<TrieNode*,26>child = {};
        bool flag= false;
        string word;
    };
 class Trie{
      public:   
    void insert(string& key, TrieNode* root)  {
          TrieNode* pnode = root;
          for(char ch : key)
          {
          if(!pnode->child[ch-'a'])
             pnode->child[ch-'a']= new TrieNode;
          pnode =   pnode->child[ch-'a'];
          }
          pnode->flag = true;
          pnode->word = key;
      }

 }; 
      
class Solution {
public:
     TrieNode *root = new TrieNode;
     unordered_set<string> result;

    
    void dfs(int i, int j ,vector<vector<char>>& board,TrieNode* node)
    {
        if(i < 0 || i >= board.size()|| j<0 || j >= board[0].size())
              return ;
        if(!board[i][j])
            return;
       char c = board[i][j];
        TrieNode* curr = node->child[c-'a'];
        if(!curr)return;
        if(curr->flag) result.insert(curr->word);
        board[i][j]= '\0'; 
            
        dfs(i - 1, j,board, curr);
        dfs(i + 1, j,board, curr);
        dfs( i, j - 1,board, curr);
        dfs( i, j + 1,board, curr);
        
        board[i][j] = c;    
            
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
     Trie t;
        for(string& word : words)
           t.insert(word,root);
       
        for(int i = 0; i < board.size();i++)
        {
            for(int j = 0 ; j < board[0].size(); j++)
            {
                dfs(i,j,board,root);
            }
        }
        return {result.begin(), result.end()};
    }
    
};
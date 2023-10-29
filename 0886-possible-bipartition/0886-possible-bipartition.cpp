class Solution {
public:
    
    bool solve(int i,unordered_map<int,vector<int>> &g,vector<int> &color){
        
        queue<int>q;
        q.push(i);
        color[i]=0;
        
        while(q.size()){
            auto parent = q.front();
            q.pop();
            
            for(auto nbr: g[parent]){
                
                if(color[nbr]==-1){
                    color[nbr] = 1-color[parent];
                    q.push(nbr);
                }else{
                    if(color[nbr] == color[parent]){
                        return false;
                    }
                }
                
            }
        }
        
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        vector<int> color(n+1,-1);
        unordered_map<int,vector<int>> g;
        
        for(auto d:dislikes){
            g[d[0]].push_back(d[1]);
            g[d[1]].push_back(d[0]);
        }
        
        for(int i=1;i<=n;i++){
            
            if(color[i]==-1){
                if(solve(i,g,color)==false){
                    return false;
                }
            }
            
        }
        
        return true;
        
    }
};
class Solution {
public:
    
    bool solve(int i, list<int> &ans, 
               vector<bool> &visited,vector<bool> &currVisited,unordered_map<int,vector<int>> &g){
        
        visited[i] = true;
        currVisited[i] = true;
        
        for(auto nbr: g[i]){
            if(visited[nbr]==false){
                if(solve(nbr,ans,visited,currVisited,g)==false){
                    return false;
                }
            }else{
                if(currVisited[nbr]==true){
                    return false;
                }
            }
        }
        
        ans.push_front(i);
        currVisited[i] = false;
        return true;
    }
    
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int,vector<int>> g;
        vector<bool>visited(numCourses,0), currVisited(numCourses,0);
        
        for(auto p:prerequisites){
            int x = p[0];
            int y = p[1];
            g[y].push_back(x); 
        }
        
        list<int> ans;
        
        for(int i=0;i<numCourses;i++){
            if(visited[i]==false){
                if(solve(i,ans,visited,currVisited,g)==false){
                    return {};
                }
                
            }
        }
        
        vector<int> result(ans.begin(),ans.end());
        return result;
        
        
    }
};
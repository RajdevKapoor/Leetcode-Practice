class Solution {
public:
    
    bool topoSort(int i, unordered_map <int,vector<int>> &graph,vector<bool> &visited,vector<bool> &currVisited,list<int> &ans){
        
        visited[i]=true;
        currVisited[i]=true;
        
        for(auto nbr:graph[i]){
            if(visited[nbr]==false){
                if(topoSort(nbr,graph,visited,currVisited,ans)){
                    return true;
                }
            }else{
                if(currVisited[nbr]){
                    return true;
                }
            }
        }
        ans.push_front(i);
        currVisited[i]=false;
        return false;
    }
    
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        unordered_map <int,vector<int>> graph;
        vector<bool>visited(n, false),currVisited(n,false);
        for(auto x: prerequisites){
            int a = x[0];
            int b = x[1];
            graph[b].push_back(a);
        }
        
        list<int> ans;
        
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                if(topoSort(i,graph,visited,currVisited,ans)){
                    return {};
                }
            }
        }
        vector<int> result (ans.begin(),ans.end());
        
        return result;
    }
};
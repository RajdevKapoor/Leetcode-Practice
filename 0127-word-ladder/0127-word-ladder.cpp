class Solution {
public:
    
    bool diffCount(string a, string b){
        int n=a.size();
        int diffCount=0;
        
        for(int i=0;i<n;i++){
            if(a[i]!=b[i]) diffCount++;
            
            if(diffCount==2) return false;
        }
        
        return true;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        if(find(wordList.begin(),wordList.end(),beginWord)==wordList.end())
            wordList.push_back(beginWord);
        
        unordered_map<string,vector<string>> graph;
        
        int n = wordList.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(diffCount(wordList[i],wordList[j])){
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        
        if(graph.count(endWord)==0) return 0;
        
        set <string> visited;
        queue<string> q;
        
        q.push(beginWord);
        
        visited.insert(beginWord);
        
        
        int level=0;
        while(q.size()){
             
            level++;
            int sz=q.size();
            
            for(int i=0;i<sz;i++){
                string src = q.front();q.pop();
                
                for(auto nbr:graph[src]){
                    
                    if(visited.find(nbr)!=visited.end()) continue;
                    
                    if(nbr==endWord) return level+1;
                        
                    visited.insert(nbr);
                    q.push(nbr);
                            
                }
                
            }
           
            
        }
         
        return 0;
    }
};
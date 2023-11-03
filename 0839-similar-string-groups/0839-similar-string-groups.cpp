class Solution {
public:
    
    bool isValid(string a, string b){
        
        int n = a.length();
        // constrainst says anagrams and same length therefore skipping size and character check
        // if wo mention ni hota to length ka diff leta and sort karke == check karta.
        
        
        int c = 0;
        
        for(int i=0;i<n;i++){
            if(a[i]!=b[i]){
                c++;
                if(c>2){
                    return false;
                }
            }
        }
        
        return true;
        
    }
    
    void dfs(string s, unordered_set<string> &vis,unordered_map<string, vector<string>> &g){
        vis.insert(s);
        
        for(auto nbr:g[s]){
            if(vis.count(nbr)==0){
                dfs(nbr,vis,g);
            }
        }
    }
    
    int numSimilarGroups(vector<string>& strs) {
        unordered_map<string, vector<string>> g;
        
        int n = strs.size();;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isValid(strs[i],strs[j])){
                    g[strs[i]].push_back(strs[j]);
                    g[strs[j]].push_back(strs[i]);
                }
            }
        }
        
        int ans =0;
        unordered_set<string> vis;
        
        for(auto s:strs){
            if(vis.count(s)==0){
                ans++;
                dfs(s,vis,g);
            }
            
        }
        return ans;
        
    }
};
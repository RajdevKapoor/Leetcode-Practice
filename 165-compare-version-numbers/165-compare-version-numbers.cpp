class Solution {
public:
    
    void solve(string &version, vector<int> &v){
        
        version+='.';
        
        string temp="";
        for(auto c:version){
            
            if(c=='.'){
                v.push_back(stoi(temp));
                temp="";
            }else{
                temp+=c;
            }
            
        }
        
        
    }
    
    int compareVersion(string version1, string version2) {
        
        vector<int> v1,v2;
        
        solve(version1,v1);
        solve(version2,v2);
        
        while(v1.size()<v2.size()) v1.push_back(0);
        while(v2.size()<v1.size()) v2.push_back(0);
        
        for(int i=0;i<v1.size();i++){
            
            if(v1[i]>v2[i]) return 1;
            
            if(v1[i]<v2[i]) return -1;
            
        }    
        return 0;
    }
};
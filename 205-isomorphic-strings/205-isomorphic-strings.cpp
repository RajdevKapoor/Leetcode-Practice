class Solution {
public:
    bool solve(string s, string t) {
        
        unordered_map<char,char> map;
        
        for(int i=0;i<s.length();i++){
            char key = s[i];
            char value = t[i];
            
            if(map.find(key)!=map.end()){
                
                if(map[key]!=value){
                    return false;
                }
                
            }else{
                map[key]=value;
            }
        }
        
        return true;
        
    }
    
    bool isIsomorphic(string s, string t) {
        
        return solve(s,t)&solve(t,s);
        
    }
};
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        string temp = "";
        vector<string> v;
        for(int i=0;i<s.length();++i){

            if(s[i]==' '){
                v.push_back(temp);
                temp = "";
            }
            else{
                temp.push_back(s[i]);
            }

        }
        v.push_back(temp);
        
        if(v.size()!=pattern.length()){
            return false;
        }
        
        unordered_map <string,string> map;
        
        for(int i=0;i<v.size();i++){  
            string key (1, pattern[i]);
            string value = v[i];
            
            if(map.find(key)!=map.end()){
                
                if(map[key]!=v[i]){
                    return false;
                }
                
            }else{
                map[key]=value;
            }
            
        }
        
        
        map.clear();
        
        for(int i=0;i<v.size();i++){  
            string value(1,pattern[i]);
            string key = v[i];
            
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
};
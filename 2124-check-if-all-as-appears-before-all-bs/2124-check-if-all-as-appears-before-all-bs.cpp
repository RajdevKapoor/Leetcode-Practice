class Solution {
public:
    bool checkString(string s) {
        
        int i=0;
        
        
        
       
        while(i<s.size() and s[i]!='b'){
              i++;
        }
            
        while(i<s.size() and s[i]!='a'){
            i++;
        }
            
        if(i<s.size()) return false;
                
        return true;
    }
};
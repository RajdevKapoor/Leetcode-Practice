class Solution {
public:
    string interpret(string c) {
        
        string ans="";
        int i=0;
        while(i<c.size()){
            if(c[i]=='G'){
                ans += 'G';
                i++;
            }else if(c[i]=='(' and c[i+1]==')'){
                ans += 'o';
                i+=2;
            }else {
                ans += "al";
                i+=4; 
            }
            
        }
        
        return ans;
        
    }
};
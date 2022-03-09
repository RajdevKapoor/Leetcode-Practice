class Solution {
public:
    int myAtoi(string s) {
        
        if(s.size()==0) return 0;
        long long int sign = 1;
        
        int i=0;
        
        while(i<s.size() and s[i]==' ') i++;
        
        
        if(i==s.size()) return 0;
        
        if(s[i]=='-'){
            sign = -1;
            i++;
        }else if(s[i]=='+'){
            i++;
        }
        
        
        long long int ans = 0;
        
        while( i<s.size() and (s[i]>='0' and s[i]<='9')){
            
           
            
            ans*=10;
            
            if(ans<=INT_MIN or ans >= INT_MAX){
                break;
            }
            ans+= s[i]-'0';
            i++;
        }
        
        ans= sign*ans;
        
        if(ans<=INT_MIN){
                return INT_MIN;
            }
            
            if(ans>=INT_MAX){
                return INT_MAX;
            }
       
        return (int)ans ;
        
    }
};
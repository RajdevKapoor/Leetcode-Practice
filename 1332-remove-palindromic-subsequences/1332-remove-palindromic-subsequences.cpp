class Solution {
public:
    int removePalindromeSub(string s) {
        
        int ca=0;
        int cb=0;
        if(s.size() == 1) return 1;
        
        int i=0,j=s.length()-1;  
                
        while(i<j){
            if(s[i]!=s[j]){
                return 2;
            }
            i++;
            j--;
        }
        
        return 1;
        
    }
};
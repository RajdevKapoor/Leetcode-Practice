class Solution {
public:
    bool isPalindrome(string s) {
        
        int i=0;
        int j= s.size()-1;
        
 
        
        while(i<=j){
            
            while (isalnum(s[i]) == false && i < j) i++;
            while (isalnum(s[j]) == false && i < j) j--;
            
             if (toupper(s[i]) != toupper(s[j])) return false;
            i++;
            j--;
             
        }
        
        return true;
        
    }
};
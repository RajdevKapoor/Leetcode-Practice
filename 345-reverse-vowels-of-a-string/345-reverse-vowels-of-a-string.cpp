class Solution {
public:
    bool isVowel(char c){
        if(c=='a' or c=='e' or c=='i' or c=='o' or c=='u' or c=='A' or c=='E' or c=='I' or c=='O' or c=='U'){
            return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        
        int n=s.length();        
        int i=0, j=n-1;
        if(n==1) return s;
        
        while(i<=j){
            
            if(isVowel(s[i]) and isVowel(s[j])){
                swap(s[i],s[j]);
                i++;
                j--;
            }
            else if(isVowel(s[i]) and !isVowel(s[j])){
                j--;
            }
            else if(!isVowel(s[i]) and isVowel(s[j])){
                i++;
            }else{
                i++;
                j--;
            }
            
        }
        
        return s;
        
    }
};
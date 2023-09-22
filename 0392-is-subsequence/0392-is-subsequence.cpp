class Solution {
public:
    bool isSubsequence(string t, string s) {
        
        int m=s.size();
        int n=t.size();
        
        int i=m-1;
        int j=n-1;
        
        while(i>-1 and j>-1){
            
            if(s[i]==t[j]){
                i--;
                j--;
            }else{
                i--;
            }
            
        }
        
        return j==-1? true:false;
        
    }
};
class Solution {
public:
    string mergeAlternately(string w1, string w2) {
        
        int i=0;
        int j=0;
        
        string ans="";
        
        while(i<w1.size() or j<w2.size()){
            
            if(i<w1.size()){
                ans+=w1[i];
            }
            
            if(j<w2.size()){
                ans+=w2[j];
            }
            
            i++;
            j++;
            
        }
        
        return ans;
        
    }
};
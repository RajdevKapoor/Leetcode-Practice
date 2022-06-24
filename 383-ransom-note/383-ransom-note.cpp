class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        unordered_map <char,int> r,m;
        
        for(auto c:ransomNote){
            r[c]++;
        }
        
        for(auto c:magazine){
            m[c]++;
        }
        
        for(auto c:ransomNote){
            if(r[c]>m[c]){
                return false;   
            }
        }
        return true;
    }
};
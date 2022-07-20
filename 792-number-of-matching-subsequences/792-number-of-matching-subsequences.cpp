class Solution {
public:
    
    bool solve(string s, string word){
        int i=0,j=0;
        
        while(i<s.length()){
            if(s[i]==word[j]){
                i++;
                j++;
                if(j==word.size()){
                    return true;
                }
            }else{
                i++;
            }
        }
        return false;
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
        
        int ans=0;
        unordered_map<string,int> map;
        
        for(auto w:words){
            map[w]++;
        }
        
        for(auto w:map){
            if(solve(s,w.first)){
                ans+=w.second;
            }
        }
        return ans;
    }
};
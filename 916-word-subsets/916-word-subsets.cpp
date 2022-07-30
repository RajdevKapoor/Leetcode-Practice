class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        vector<int>freq(26,0);
        
        for(auto w2:words2){
            
            vector<int> tempfreq(26,0); 
            for(auto c:w2){
                tempfreq[c-'a']++;
                
                freq[c-'a'] =max(freq[c-'a'],tempfreq[c-'a']);
                
            }
        }
        
        vector<string> ans;
        
        for(auto w:words1){
            
            bool flag = true;
            vector<int> wfreq(26,0);
            for(auto c:w){
                wfreq[c-'a']++;
            }
            
            for(int i=0;i<26;i++){
                if(freq[i]>wfreq[i]){
                    flag=false;
                    break;
                }
            }
            
            if(flag){
                ans.push_back(w);
            }
        }
        
        return ans;
        
    }
};
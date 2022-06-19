class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        
        int ans=0;
        
        unordered_map <string,int> mp1,mp2;
        
        for(auto s:words1){
            mp1[s]++;
        }
        
        for(auto s:words2){
            mp2[s]++;
        }
        for(auto s:words1){
            if(mp1[s]==1 and mp2[s]==1){
                ans++;
            }
        }
        
        return ans;
    }
};